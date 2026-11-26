#include <choco/runtime.hpp>
#if defined(CHOCO_ANDROID)
#include <fstream>
#endif

namespace choco::runtime {
std::string process_name() {
#if defined(CHOCO_ANDROID)
    std::ifstream cmdline("/proc/self/cmdline");
    std::string name;
    if (cmdline) std::getline(cmdline, name, '\0');
    return name;
#else
    return {};
#endif
}
bool is_geometry_dash() {
#if defined(CHOCO_ANDROID)
    constexpr char target[] = "com.robtopx.geometryjump";
    const auto name = process_name();
    return name == target || name.starts_with(std::string(target) + ":");
#else
    return false;
#endif
}
}
