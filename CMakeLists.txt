cmake_minimum_required(VERSION 3.19)
project(DS)

set(CMAKE_CXX_STANDARD 11)

include_directories(src
        src/DSInclude
        )

add_executable(DS main.cpp
        src/DSInclude/ADT_Triplet.h
        src/DSInclude/const.h
        src/DSInclude/ADT_Triplet.cpp
        src/DSInclude/ADT_List_Sq.h
        src/DSInclude/ADT_List_Sq.cpp
        )

#file (GLOB_RECURSE files *.cpp)
#foreach (file ${files})
#    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
#    add_executable(${exe} ${file})
#    message(\ \ \ \ --\ src/${exe} .c\ will\ be\ compiled\ to\ bin/${exe})
#endforeach ()