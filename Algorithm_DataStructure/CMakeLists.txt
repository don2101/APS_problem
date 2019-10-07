cmake_minimum_required(VERSION 3.14)
project(Algorithm_DataStructure)

set(CMAKE_CXX_STANDARD 11)

add_executable(Algorithm_DataStructure main.cpp Sort/MergeSort.cpp Sort/MergeSort.h Sort/InsertionSort.cpp Sort/InsertionSort.h Test/SortTest.cpp Test/SortTest.h Tree/IndexedTree.cpp Tree/IndexedTree.h Test/TreeTest.cpp Test/TreeTest.h)