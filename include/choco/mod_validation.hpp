#pragma once

#include <choco/mod_api.hpp>

namespace choco::mods {
/// Validates a descriptor returned by a mod query function against the current ABI.
bool validate_info(const ChocoModInfo& info);
}
