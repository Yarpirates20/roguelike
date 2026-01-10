cmake_minimum_required(VERSION 3.26)
project(roguelike_tests CXX)

## GoogleTest setup
include(FetchContent)
FetchContent_Declare(
    googletest
     URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

file(GLOB TEST_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*_test.cpp)

if(TEST_SOURCES)
    add_executable(roguelike_tests ${TEST_SOURCES})
    target_link_libraries(roguelike_tests PRIVATE roguelike_lib gtest_main)
    gtest_discover_tests(roguelike_tests)
endif()
