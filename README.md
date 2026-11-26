![Minha foto](img/20261125_184919_0000.png)
# Choco Loader

Independent native mod-loader project for Geometry Dash Android 2.2091.

## Current stage

**Android JNI entry scaffold (0.1.1):** Android's JNI loader entry point (`JNI_OnLoad`) now logs and invokes the bootstrap when `libchoco.so` is loaded through the Java runtime. The existing native constructor is retained; bootstrap's atomic guard prevents duplicate initialization.

This does **not** inject the library into Geometry Dash, attach to GD, or install hooks/mod loading yet.

## Build

Build with the Android NDK and CMake for the target ABI. Intended initial target: Android ARM64.

## Project structure

- `include/choco/`: public loader headers
- `src/`: native implementation
- `mods/`: planned mod directory (not implemented yet)

## License

See [LICENSE](LICENSE).
