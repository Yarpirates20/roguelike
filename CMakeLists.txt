cmake_minimum_required(VERSION 3.26)
project (roguelike LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Find Dependencies
find_package(Curses REQUIRED)

# 2. Define the Library (the Engine)
# Gathers all source files EXCEPT main.cpp
file(GLOB_RECURSE ENGINE_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/core/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/db/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/ui/*.cpp"
)

# Exclude main.cpp if you collect all .cpp files
list(REMOVE_ITEM ENGINE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

if(NOT ENGINE_SOURCES)
    message(FATAL_ERROR "No engine sources found (ENGINE_SOURCES is empty). Check glob patterns.")
endif()

add_library(roguelike_lib ${ENGINE_SOURCES})

# 3. Setup Includes and Linking
# PUBLIC means anything linking to this lib (like tests) also get these includes.
target_include_directories(roguelike_lib PUBLIC "${PROJECT_SOURCE_DIR}/include")

target_link_libraries(roguelike_lib PUBLIC
    Curses::Curses
)

# 4. Define the Executable (Game Entry Point)
add_executable(roguelike_run src/main.cpp)
target_link_libraries(roguelike_run PRIVATE roguelike_lib)

message("Configuring roguelike project")

enable_testing()
add_subdirectory(tests)