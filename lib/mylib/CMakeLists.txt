cmake_minimum_required(VERSION 3.20)
project(mylib)

include(CTest)

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(test)
