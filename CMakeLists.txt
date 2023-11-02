# set the minimum version
cmake_minimum_required(VERSION 3.10)

# Project name
project(PriorityQueue VERSION 1.0)

# Let's add the executable name now
add_executable(main.out ${SOURCES})

# Set SOURCES var
target_sources(main.out PRIVATE src/main.cpp src/EmptyException.cpp include/BinaryHeapPriorityQueue.hpp)

# Have it include the include folder
target_include_directories(main.out PRIVATE include)