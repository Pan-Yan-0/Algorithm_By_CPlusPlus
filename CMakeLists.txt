cmake_minimum_required(VERSION 3.26)
project(Project1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project1 main.cpp
        算法/ASCALL表.cpp
        算法/ASCALLMin.cpp
        算法/lengthOfLIS.h
        算法/lengthOfLIS.cpp
        算法/numDistinct.cpp)
