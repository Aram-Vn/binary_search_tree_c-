# CMakeLists.txt

cmake_minimum_required(VERSION 3.12)
project(BinarySearchTree)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)

# Add the source files
set(SOURCES
    src/binary_search_tree.h
    src/binary_search_tree_impl.hpp
    src/main.cpp
)

# Create an executable
add_executable(BinarySearchTree ${SOURCES})