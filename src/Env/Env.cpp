//
// Created by 刘科 on 2025/10/8.
//

#include "include/Env/Env.h"
#include <iostream>


Env::Env() {
#if OS_IS_MACOSX
    std::cout << "env os type macosx\n";
#elif OS_IS_WIN
    std::cout << "env os type win\n";
#elif OS_IS_LINUX
    std::cout << "env os type linux\n";
#else
    std::cout << "env os type other\n";
#endif
}
