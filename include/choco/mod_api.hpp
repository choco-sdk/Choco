#pragma once

#include <cstdint>

#if defined(_WIN32)
#define CHOCO_MOD_EXPORT __declspec(dllexport)
#else
#define CHOCO_MOD_EXPORT __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

/// Choco native mod ABI. Keep this interface C-compatible for cross-compiler use.
#define CHOCO_MOD_API_VERSION 1u

typedef void (*ChocoLogFn)(int level, const char* message);

typedef struct ChocoHostAPI {
    std::uint32_t abi_version;
    std::uint32_t struct_size;
    ChocoLogFn log;
} ChocoHostAPI;

typedef bool (*ChocoModInitFn)(const ChocoHostAPI* host);
typedef void (*ChocoModShutdownFn)();

typedef struct ChocoModInfo {
    std::uint32_t abi_version;
    std::uint32_t struct_size;
    const char* id;
    const char* name;
    const char* version;
    ChocoModInitFn initialize;
    ChocoModShutdownFn shutdown;
} ChocoModInfo;

/// Mods export a function with this exact symbol name that fills a descriptor.
typedef bool (*ChocoModQueryFn)(ChocoModInfo* out_info);

#define CHOCO_MOD_QUERY_SYMBOL "choco_mod_query"

#ifdef __cplusplus
}
#endif
