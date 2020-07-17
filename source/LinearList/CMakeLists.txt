cmake_minimum_required(VERSION 3.15)
project(LinearList)

set(CMAKE_CXX_STANDARD 14)

add_executable(LinearList main.cpp  SequenceList.h SequenceList.c flags.h LinkedList.c LinkedList.h )