cmake_minimum_required(VERSION 3.31)
project(CmakeTest)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src/OneModule)

add_executable(CmakeTest main.cpp)

target_link_libraries(CmakeTest OneModule)
