#pragma once

#include <cstddef>

namespace choco::module {

using InitFn = bool (*)();
using ShutdownFn = void (*)();

struct Descriptor {
    const char* id;
    const char* version;
    InitFn initialize;
    ShutdownFn shutdown;
};

enum class Status {
    registered,
    duplicate_id,
    registration_closed,
    invalid_descriptor
};

/// Register a module before initialize_all() is called.
/// Module IDs must be unique and descriptors must remain valid for the process lifetime.
Status register_module(const Descriptor& descriptor);

/// Initializes registered modules in registration order. Safe to call repeatedly.
void initialize_all();

/// Shuts down successfully initialized modules in reverse order.
void shutdown_all();

/// Number of modules registered, including modules whose initialization failed.
std::size_t count();

/// Number of modules whose initialize callback returned true.
std::size_t initialized_count();

/// Registration is closed after initialize_all() begins.
bool registration_open();

} // namespace choco::module
