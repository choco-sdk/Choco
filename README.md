![Minha foto](img/20261125_184919_0000.png)
# Choco Loader

Independent native mod-loader project for Geometry Dash Android 2.2091.

## Current stage

**Bootstrap scaffold (0.1.0):** the shared library logs a startup message when loaded on Android. This is only the first foundation; it does not yet inject itself into Geometry Dash, install hooks, or load mods.

## Build

Build with the Android NDK and CMake for the target ABI. The initial scaffold is intended for Android ARM64.

## Project structure

- `include/choco/`: public loader headers
- `src/`: native implementation
- `mods/`: planned mod directory (not implemented yet)

## License

See [LICENSE](LICENSE).
