# CMake 3.21 required to build; could probably be set lower
cmake_minimum_required(VERSION 3.21.0)

# Prevent in-source builds
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_CURRENT_BINARY_DIR)
  message(FATAL_ERROR "Prevented in-tree build. Please create a build directory outside of the Outcast source code and run /"cmake -S ${CMAKE_SOURCE_DIR} -B ./" from there")
endif()

# Set the project with latest version
project(outcast VERSION "0.0.1")

# Set the assets files for the project
set(ASSETS assets)
file(COPY ${ASSETS} DESTINATION ${CMAKE_BINARY_DIR})

# List of sources for the project
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")

# Build imgui
set(Imgui_SOURCES
    vendor/imgui/imconfig.h
    vendor/imgui/imgui.cpp
    vendor/imgui/imgui.h
    vendor/imgui/imgui_demo.cpp
    vendor/imgui/imgui_draw.cpp
    vendor/imgui/imgui_internal.h
    vendor/imgui/imgui_widgets.cpp
    vendor/imgui/imstb_rectpack.h
    vendor/imgui/imstb_textedit.h
    vendor/imgui/imstb_truetype.h
	  vendor/imgui/imgui_tables.cpp
    vendor/imgui/backends/imgui_impl_sdlrenderer3.cpp
    vendor/imgui/backends/imgui_impl_sdlrenderer3.h
    vendor/imgui/backends/imgui_impl_sdl3.cpp
    vendor/imgui/backends/imgui_impl_sdl3.h
)

# Set the executable file for the project
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${Imgui_SOURCES})

# Make sure submodules exist before building
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/vendor/SDL/CMakeLists.txt")
	message(FATAL_ERROR "Unable to locate the SDL3 submodule in filesystem. Try running `git submodule update --init --recursive`.")
endif()


if(NOT EXISTS "${PROJECT_SOURCE_DIR}/vendor/SDL_image/CMakeLists.txt")
	message(FATAL_ERROR "Unable to locate the SDL3_image submodule in filesystem. Try running `git submodule update --init --recursive`.")
endif()

# No need to build tests when bulding SDL
option(SDL_TEST OFF)

# Build the submodules along with the project
add_subdirectory(vendor/SDL)
add_subdirectory(vendor/SDL_image)
add_subdirectory(vendor/nativefiledialog)

# Force minimum compatability to be with C++14
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_14)

# Add includes for the project
target_include_directories(
	${PROJECT_NAME} PRIVATE vendor/imgui
	${PROJECT_NAME} PRIVATE vendor/imgui/backends
	${PROJECT_NAME} PRIVATE vendor/SDL/include
	${PROJECT_NAME} PRIVATE vendor/SDL_image/include
  ${PROJECT_NAME} PRIVATE vendor/nativefiledialog/include
	${PROJECT_NAME} PRIVATE include
)

# Add and link libraries to project
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3 SDL3_image::SDL3_image nfd)

# Enable lto on the target if supported (in Release mode)
if(CMAKE_BUILD_TYPE STREQUAL "Release")
	set_property(TARGET ${PROJECT_NAME} PROPERTY INTERPROCEDURAL_OPTIMIZATION True)
endif()

# Enable PIE/PIC on the target if supported
set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE True)