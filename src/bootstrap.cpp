#include <choco/bootstrap.hpp>
#include <atomic>
#if defined(CHOCO_ANDROID)
#include <android/log.h>
#else
#include <cstdio>
#endif

namespace choco {
namespace {
std::atomic<bool> g_bootstrapped{false};
void log_info(const char* message) {
#if defined(CHOCO_ANDROID)
    __android_log_write(ANDROID_LOG_INFO, "Choco", message);
#else
    std::fprintf(stderr, "[Choco] %s\n", message);
#endif
}
} // namespace

void bootstrap() {
    bool expected = false;
    if (!g_bootstrapped.compare_exchange_strong(expected, true)) return;
    log_info("Native bootstrap started.");
    log_info("Target: Android / Geometry Dash 2.2091 (initial scaffold).");
    log_info("Core initialization complete; hooks and mod loading are not enabled yet.");
}

bool is_bootstrapped() { return g_bootstrapped.load(); }
} // namespace choco
