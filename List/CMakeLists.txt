cmake_minimum_required(VERSION 3.25)
project(List VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_library(ListLib ${SOURCES})

add_executable(List 
    src/List.cpp
    src/Files.cpp
    src/Grouping.cpp
    src/Stud.cpp
)

target_link_libraries(List ListLib)
enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(ProjectTest tests/test.cpp)
target_link_libraries(ProjectTest PRIVATE gtest gtest_main ListLib)
target_include_directories(ProjectTest PRIVATE include)

add_test(NAME ProjectTest COMMAND ProjectTest)
