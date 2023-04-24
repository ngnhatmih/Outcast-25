cmake_minimum_required(VERSION 3.21.0)

# The Outcast Engine CMake file

file(GLOB_RECURSE source_list "${PROJECT_SOURCE_DIR}/Engine/*.cpp")

add_library(outcast ${source_list})

# Force minimum compatability to be with C++14
target_compile_features(outcast PRIVATE cxx_std_14)

target_include_directories(outcast PUBLIC "${PROJECT_SOURCE_DIR}/Engine" "${PROJECT_SOURCE_DIR}/vendor/SDL/include")
target_link_directories(outcast PUBLIC SDL3::SDL3)

