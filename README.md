![Minha foto](img/20261125_184919_0000.png)
# Choco Loader

Independent native mod-loader project for Geometry Dash Android 2.2091.

## Current stage

**Runtime recognition, hook interface, module registry, and mod ABI (0.1.4):**
- JNI entry logs the process name and runs bootstrap only after Geometry Dash is recognized.
- Bootstrap is no longer invoked from a library constructor, avoiding premature initialization before process validation.
- Runtime detection reads `/proc/self/cmdline` on Android.
- Hook API added. Dobby backend is optional and disabled by default; configure `CHOCO_WITH_DOBBY=ON` only when your build supplies a CMake target named `dobby_static`.
- Internal module registry supports unique IDs, init callbacks, optional shutdown callbacks, initialization in registration order, and shutdown in reverse order. Registration closes once initialization starts.
- Bootstrap initializes the registry; dynamic module discovery/loading is not implemented yet.\n- C-compatible mod ABI header defines versioned descriptors, host logging callback, init/shutdown callbacks, and query symbol. Descriptor validation helper is implemented; loading mods from disk is still pending.

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


## Mod ABI (early)

A native mod includes `choco/mod_api.hpp` and exports the query symbol:

```cpp
#include <choco/mod_api.hpp>

static bool on_init(const ChocoHostAPI* host) {
    if (host && host->log) host->log(1, "Example mod initialized");
    return true;
}
static void on_shutdown() {}

extern "C" CHOCO_MOD_EXPORT bool choco_mod_query(ChocoModInfo* out) {
    if (!out) return false;
    *out = ChocoModInfo{
        CHOCO_MOD_API_VERSION, sizeof(ChocoModInfo),
        "example.hello", "Hello Mod", "1.0.0",
        on_init, on_shutdown
    };
    return true;
}
```

This ABI is a contract only: mods are not discovered, loaded, or executed yet. Build and runtime verification is still required.
