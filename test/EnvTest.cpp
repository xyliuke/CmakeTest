//
// Created by 刘科 on 2025/10/8.
//

#include <catch2/catch_test_macros.hpp>
#include <iostream>
// #include <Env/Env.h>
#include <Env/env_config.h>

TEST_CASE("ENV", "[env_test]") {
#if OS_IS_MACOSX
    std::cout << "os type macosx\n";
#elif OS_IS_WIN
    std::cout << "os type win\n";
#elif OS_IS_LINUX
    std::cout << "os type linux\n";
#else
    std::cout << "os type other\n";
#endif

    // Env env;
}