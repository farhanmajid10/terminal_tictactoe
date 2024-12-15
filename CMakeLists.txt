# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(TicTacToe VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Source files
file(GLOB SOURCES src/*.cpp)

# Output executable
add_executable(tictactoe ${SOURCES})

# Set executable output location
# For single-configuration generators (e.g., Makefiles)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# For multi-configuration generators (e.g., Visual Studio)
set_target_properties(tictactoe PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}
)

# Optional: Add compile warnings
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(tictactoe PRIVATE -Wall -Wextra -pedantic)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(tictactoe PRIVATE /W4)
endif()
