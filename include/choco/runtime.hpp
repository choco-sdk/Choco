#pragma once

#include <string>

namespace choco::runtime {
/// Returns current process command name (Android reads /proc/self/cmdline).
std::string process_name();
/// True only when running in the Geometry Dash Android package.
bool is_geometry_dash();
}
