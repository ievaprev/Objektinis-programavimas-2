cmake_minimum_required(VERSION 3.25)
project(Objektinis-programavimas VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Objektinis-programavimas
    src/Vector.cpp
    src/Files.cpp
    src/Grouping.cpp
    src/Stud.cpp
)

include_directories(${PROJECT_SOURCE_DIR}/include)

set_target_properties(Objektinis-programavimas PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_BINARY_DIR}/x64/Debug
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_BINARY_DIR}/x64/Release
)
