cmake_minimum_required(VERSION 3.19)
project(DS)

set(CMAKE_CXX_STANDARD 11)

include_directories(src
        src/DSInclude
        src/DSInclude/sample
        )

add_executable(DS main.cpp
        src/DSInclude/sample_Triplet.h
        src/DSInclude/const.h
        src/DSInclude/sample/sample_Triplet.cpp)

#file (GLOB_RECURSE files *.cpp)
#foreach (file ${files})
#    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
#    add_executable(${exe} ${file})
#    message(\ \ \ \ --\ src/${exe} .c\ will\ be\ compiled\ to\ bin/${exe})
#endforeach ()