cmake_minimum_required(VERSION 3.13)
project(Speller)

set(CMAKE_CXX_STANDARD 14)

add_executable(Speller main.cpp
        sources/stdvectorChecker.cpp
        sources/HashTableChecker.cpp
        sources/StdUnorderedSetChecker.cpp
        sources/BinTreeChecker.cpp
        sources/Checker.cpp
        sources/bintree.cpp)

