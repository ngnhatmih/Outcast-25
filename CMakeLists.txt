# CMake 3.21 required to build; could probably be set lower
cmake_minimum_required(VERSION 3.21.0)

# Prevent in-source builds
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_CURRENT_BINARY_DIR)
  message(FATAL_ERROR "Prevented in-tree build. Please create a build directory outside of the Outcast source code and run \"cmake -S ${CMAKE_SOURCE_DIR} -B .\" from there")
endif()

# Set the project with latest version
project(outcast VERSION "0.0.1")

# Make sure submodules exist before building
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/vendor/SDL/CMakeLists.txt")
    message(FATAL_ERROR "Unable to locate the SDL3 submodule in filesystem. Try running `git submodule update --init --recursive`.")
endif()

# No need to build tests when bulding SDL
option(SDL_TEST OFF)

# Build the SDL submodule along with the project
add_subdirectory(vendor/SDL)

add_subdirectory(Engine)
add_subdirectory(Game)

# Enable lto on the target if supported (in Release mode)
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set_property(TARGET outcast game PROPERTY INTERPROCEDURAL_OPTIMIZATION True)
endif()

# Enable PIE/PIC on the target if supported
set_property(TARGET outcast game PROPERTY POSITION_INDEPENDENT_CODE True)