#include <choco/module.hpp>

#include <mutex>
#include <string>
#include <vector>

namespace choco::module {
namespace {
struct Entry {
    Descriptor descriptor{};
    bool initialized{false};
};

std::mutex g_mutex;
std::vector<Entry> g_modules;
bool g_initialization_started{false};
bool g_shutdown_started{false};
}

Status register_module(const Descriptor& descriptor) {
    if (!descriptor.id || descriptor.id[0] == '\0' || !descriptor.initialize)
        return Status::invalid_descriptor;

    std::lock_guard<std::mutex> lock(g_mutex);
    if (g_initialization_started) return Status::registration_closed;

    for (const auto& entry : g_modules) {
        if (std::string(entry.descriptor.id) == descriptor.id)
            return Status::duplicate_id;
    }

    g_modules.push_back(Entry{descriptor, false});
    return Status::registered;
}

void initialize_all() {
    {
        std::lock_guard<std::mutex> lock(g_mutex);
        if (g_initialization_started) return;
        g_initialization_started = true;
    }

    // Call module code outside the lock to avoid deadlocks if it calls back into Choco.
    for (std::size_t i = 0; i < g_modules.size(); ++i) {
        bool ok = false;
        const auto initialize = g_modules[i].descriptor.initialize;
        if (initialize) ok = initialize();
        g_modules[i].initialized = ok;
    }
}

void shutdown_all() {
    {
        std::lock_guard<std::mutex> lock(g_mutex);
        if (g_shutdown_started) return;
        g_shutdown_started = true;
    }

    for (std::size_t i = g_modules.size(); i > 0; --i) {
        auto& entry = g_modules[i - 1];
        if (entry.initialized && entry.descriptor.shutdown) {
            entry.descriptor.shutdown();
            entry.initialized = false;
        }
    }
}

std::size_t count() {
    std::lock_guard<std::mutex> lock(g_mutex);
    return g_modules.size();
}

std::size_t initialized_count() {
    std::lock_guard<std::mutex> lock(g_mutex);
    std::size_t total = 0;
    for (const auto& entry : g_modules) total += entry.initialized ? 1U : 0U;
    return total;
}

bool registration_open() {
    std::lock_guard<std::mutex> lock(g_mutex);
    return !g_initialization_started;
}

} // namespace choco::module
