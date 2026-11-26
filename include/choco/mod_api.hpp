#pragma once

#include <stdint.h>
#ifndef __cplusplus
#include <stdbool.h>
#endif

#if defined(_WIN32)
#define CHOCO_MOD_EXPORT __declspec(dllexport)
#else
#define CHOCO_MOD_EXPORT __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define CHOCO_MOD_API_VERSION 1u

typedef void (*ChocoLogFn)(int level, const char* message);

typedef struct ChocoHostAPI {
    uint32_t abi_version;
    uint32_t struct_size;
    ChocoLogFn log;
} ChocoHostAPI;

typedef bool (*ChocoModInitFn)(const ChocoHostAPI* host);
typedef void (*ChocoModShutdownFn)(void);

typedef struct ChocoModInfo {
    uint32_t abi_version;
    uint32_t struct_size;
    const char* id;
    const char* name;
    const char* version;
    ChocoModInitFn initialize;
    ChocoModShutdownFn shutdown;
} ChocoModInfo;

typedef bool (*ChocoModQueryFn)(ChocoModInfo* out_info);

#define CHOCO_MOD_QUERY_SYMBOL "choco_mod_query"

#ifdef __cplusplus
}
#endif
