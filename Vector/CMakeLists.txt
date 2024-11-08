cmake_minimum_required(VERSION 3.10)
project(Objektinis-programavimas VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Objektinis-programavimas
    src/Files.cpp
    src/Grouping.cpp
    src/Stud.cpp
    src/Vector.cpp
)

include_directories(${PROJECT_SOURCE_DIR}/include)
