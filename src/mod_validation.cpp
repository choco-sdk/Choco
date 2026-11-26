#include <choco/mod_validation.hpp>

namespace choco::mods {
bool validate_info(const ChocoModInfo& info) {
    if (info.abi_version != CHOCO_MOD_API_VERSION) return false;
    if (info.struct_size < sizeof(ChocoModInfo)) return false;
    if (!info.id || info.id[0] == '\0') return false;
    if (!info.name || info.name[0] == '\0') return false;
    if (!info.version || info.version[0] == '\0') return false;
    if (!info.initialize) return false;
    return true;
}
}
