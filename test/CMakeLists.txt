project(CMakeTestTests)

enable_testing()

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../src/OneModule OneModule)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../src/Env Env)
add_subdirectory(Catch2)

set(SRC
    OneModuleTest.cpp
    EnvTest.cpp
)

add_executable(OneModuleTest ${SRC})

#target_include_directories(${CMAKE_CURRENT_LIST_DIR}/Catch2)
target_link_libraries(OneModuleTest PRIVATE Catch2::Catch2WithMain OneModule Env)

add_test(NAME OneModuleTest
        COMMAND $<TARGET_FILE:OneModuleTest> --success
)