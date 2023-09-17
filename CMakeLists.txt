cmake_minimum_required(VERSION 3.26)
project(Project1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project1 main.cpp
        算法/ASCALL表.cpp
        算法/ASCALLMin.cpp
        算法/lengthOfLIS.h
        算法/lengthOfLIS.cpp
        算法/numDistinct.cpp
        算法/findNumberOfLIS.h
        算法/findNumberOfLIS.cpp
        teacherDay.cpp
        算法/findLongestChain.cpp
        算法/longestSubsequence.cpp
        算法/longestArithSeqLength.cpp
        算法/maxEnvelopes.h
        算法/maxEnvelopes.cpp
        算法/longestObstacleCourseAtEachPosition.h
        算法/longestObstacleCourseAtEachPosition.cpp)
