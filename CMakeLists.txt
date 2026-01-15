cmake_minimum_required(VERSION 3.26)
project (roguelike LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

# 1. Find Dependencies
find_package(Curses REQUIRED)

# 2. Add executable
file(GLOB SOURCES "src/*.cpp")

add_executable(rogue_run ${SOURCES})


target_include_directories(rogue_run PRIVATE 
    src
    ${CURSES_INCLUDE_DIRS}
)

target_link_libraries(rogue_run PRIVATE
    ${CURSES_LIBRARIES}
)

message("Configuring roguelike project")

# enable_testing()
# add_subdirectory(tests)