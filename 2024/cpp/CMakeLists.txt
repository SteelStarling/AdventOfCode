cmake_minimum_required(VERSION 3.10)

# Set name
project(AdventOfCode_2024)

# Specify C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Link executables
add_executable(main main.cpp)


# Connect libraries
add_library(AOC_24 AOC24.cpp)
add_library(Solution_24 Solution24.cpp)

add_dependencies(main, AOC_24) 
add_dependencies(AOC_24, Solution_24) 

# Handle subdirectories
add_subdirectory(Day01)
add_subdirectory(Day02)
add_subdirectory(Day03)
add_subdirectory(Day04)