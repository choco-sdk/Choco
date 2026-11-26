#pragma once

namespace choco::hook {
enum class Status {
    success,
    backend_unavailable,
    invalid_arguments,
    failed
};

/// Installs an in-process hook at a caller-provided address when built with Dobby.
/// This API does not locate targets or inject Choco into another process.
Status install(void* target, void* replacement, void** original);
bool available();
}
