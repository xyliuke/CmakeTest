cmake_minimum_required(VERSION 3.31)
project(CmakeTest)

set(CMAKE_CXX_STANDARD 20)

option(ENABLE_TESTS "build unit test" ON)

if (ENABLE_TESTS)
    message("enable ut ${ENABLE_TESTS}")
    add_subdirectory(test)
else ()
    message("disable ut")
    add_subdirectory(src/OneModule)

    add_executable(CmakeTest main.cpp)

    target_link_libraries(CmakeTest OneModule)
endif ()


