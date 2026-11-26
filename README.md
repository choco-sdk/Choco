![Minha foto](img/20261125_184919_0000.png)
# Choco Loader

Independent native mod-loader project for Geometry Dash Android 2.2091.

## Current stage

**Runtime recognition and hook interface (0.1.2):**
- JNI entry logs the process name and only runs bootstrap when it matches the Geometry Dash Android package.
- Runtime detection reads `/proc/self/cmdline` on Android.
- Hook API added. Dobby backend is optional and disabled by default; configure `CHOCO_WITH_DOBBY=ON` only when your build supplies a CMake target named `dobby_static`.

This is not an injector. Choco must already be loaded into the app process. No GD function addresses or hook targets are configured.

## Build

Build with Android NDK and CMake. Initial target: Android ARM64.

## Project structure

- `include/choco/`: public loader headers
- `src/`: native implementation
- `mods/`: planned mod directory

## Dobby

Dobby is a third-party dependency. Its upstream repository states Apache-2.0; review and retain its license and notices before bundling. Choco does not vendor Dobby yet.

## License

See [LICENSE](LICENSE).
