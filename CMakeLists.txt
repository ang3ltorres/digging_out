cmake_minimum_required(VERSION 3.28)
project(medaw VERSION 0.0.1 LANGUAGES CXX)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Source files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/src/*.cpp)

# Define the library
add_executable(do ${SOURCES})

# Include directories
target_include_directories(do PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/source/include
	${CMAKE_CURRENT_SOURCE_DIR}/build/dep/include
)

# Precompiled headers
target_precompile_headers(do PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/source/include/pch.hpp
)

# Compilation options
target_compile_options(do PRIVATE -Wall -Wextra -Wpedantic -fmax-errors=1)

# Link dependencies
target_link_directories(do PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/build/dep/bin
)

target_link_libraries(do PUBLIC
	glfw
	GLEW
	freetype
	png
	GL
)

