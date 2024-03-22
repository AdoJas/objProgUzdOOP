cmake_minimum_required(VERSION 3.26)
project(objProgUzd)

set(CMAKE_CXX_STANDARD 14)

include_directories(Pazymiai)

add_executable(objProgUzd
        Pazymiai/Common.cpp
        Pazymiai/Common.h
        Pazymiai/PazymiaiArrays.cpp
        Pazymiai/PazymiaiArrays.h
        Pazymiai/PazymiaiVectors.cpp
        Pazymiai/PazymiaiVectors.h
        Pazymiai/Program.cpp)
