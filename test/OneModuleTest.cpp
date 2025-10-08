//
// Created by 刘科 on 2025/10/7.
//
#include <iostream>
#include <Catch2/catch_test_macros.hpp>

#include "OneModule/One.h"

TEST_CASE("test1", "[test111]") {
    REQUIRE(One::getInt() == 5);
}