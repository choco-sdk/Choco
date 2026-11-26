cmake_minimum_required(VERSION 3.22)
project(ChocoLoader VERSION 0.1.2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(CHOCO_WITH_DOBBY "Enable Dobby hook backend (requires Dobby target)" OFF)

add_library(choco_loader SHARED
    src/bootstrap.cpp
    src/android_entry.cpp
    src/runtime.cpp
    src/hook.cpp
)
target_include_directories(choco_loader PUBLIC include)
target_compile_options(choco_loader PRIVATE -Wall -Wextra -Wpedantic)

if(ANDROID)
    find_library(android_log log REQUIRED)
    target_link_libraries(choco_loader PRIVATE ${android_log})
    target_compile_definitions(choco_loader PRIVATE CHOCO_ANDROID=1)
endif()

if(CHOCO_WITH_DOBBY)
    if(NOT TARGET dobby)
        message(FATAL_ERROR "CHOCO_WITH_DOBBY=ON requires a Dobby CMake target named 'dobby'. Add Dobby to your build first.")
    endif()
    target_link_libraries(choco_loader PRIVATE dobby)
    target_compile_definitions(choco_loader PRIVATE CHOCO_WITH_DOBBY=1)
endif()

set_target_properties(choco_loader PROPERTIES
    OUTPUT_NAME choco
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN YES
)
