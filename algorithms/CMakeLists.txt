# cmake_minimum_required(VERSION <specify CMake version here>)
project(algorithms)

set(CMAKE_CXX_STANDARD 11)

add_executable(algorithms main.cpp SortTestHelper.h Student.h CockTailSort.h BubbleSort.h InsertionSort.h ShellSort.h MergeSort.h)