#include <choco/hook.hpp>

#if defined(CHOCO_WITH_DOBBY)
#include <dobby.h>
#endif

namespace choco::hook {
bool available() {
#if defined(CHOCO_WITH_DOBBY)
    return true;
#else
    return false;
#endif
}

Status install(void* target, void* replacement, void** original) {
    if (!target || !replacement || !original) return Status::invalid_arguments;
#if defined(CHOCO_WITH_DOBBY)
    const int result = DobbyHook(target, replacement, original);
    return result == 0 ? Status::success : Status::failed;
#else
    (void)target;
    (void)replacement;
    (void)original;
    return Status::backend_unavailable;
#endif
}
} // namespace choco::hook
