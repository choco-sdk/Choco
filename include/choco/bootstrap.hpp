#pragma once

namespace choco {
/// Starts Choco's native loader bootstrap. Safe to call more than once.
void bootstrap();
/// Returns true once bootstrap has completed its initial setup.
bool is_bootstrapped();
} // namespace choco
