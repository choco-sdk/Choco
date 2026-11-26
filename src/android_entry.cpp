#include <choco/android_entry.hpp>
#include <choco/bootstrap.hpp>
#include <choco/runtime.hpp>

#if defined(CHOCO_ANDROID)
#include <jni.h>
#include <android/log.h>

namespace choco {
void android_jni_entry() {
    const auto process = runtime::process_name();
    __android_log_print(ANDROID_LOG_INFO, "Choco", "JNI entry in process: %s", process.c_str());
    if (!runtime::is_geometry_dash()) {
        __android_log_write(ANDROID_LOG_INFO, "Choco", "Target process not recognized; bootstrap skipped.");
        return;
    }
    __android_log_write(ANDROID_LOG_INFO, "Choco", "Geometry Dash process recognized.");
    bootstrap();
}
}

extern "C" __attribute__((visibility("default")))
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    (void)vm;
    (void)reserved;
    choco::android_jni_entry();
    return JNI_VERSION_1_6;
}
#else
namespace choco {
void android_jni_entry() {}
}
#endif
