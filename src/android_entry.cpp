#include <choco/android_entry.hpp>
#include <choco/bootstrap.hpp>

#if defined(CHOCO_ANDROID)
#include <jni.h>
#include <android/log.h>

namespace choco {
void android_jni_entry() {
    __android_log_write(ANDROID_LOG_INFO, "Choco", "JNI entry reached.");
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
