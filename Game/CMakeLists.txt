cmake_minimum_required(VERSION 3.21.0)

# The Game CMake file

file(GLOB_RECURSE SOURCE_FILES "${PROJECT_SOURCE_DIR}/Game/*.cpp")

add_executable(game ${SOURCE_FILES})

# Force minimum compatability to be with C++14
target_compile_features(game PRIVATE cxx_std_14)

target_include_directories(game PUBLIC "${PROJECT_SOURCE_DIR}/Engine" "${PROJECT_SOURCE_DIR}/vendor/SDL/include")
target_link_directories(game PUBLIC outcast SDL3::SDL3)
