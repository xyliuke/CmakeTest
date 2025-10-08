
set(SRC
    Env.cpp
)

add_library(Env ${SRC})

target_include_directories(Env
        PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include
        INTERFACE ${CMAKE_CURRENT_LIST_DIR}/interface
)

#target_include_directories(Env PUBLIC ${CMAKE_CURRENT_LIST_DIR}/env_config.h)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Configuring on/for Linux")
#    target_compile_definitions(Env PUBLIC "OS_IS_LINUX")
    set(_OS_IS_XXX OS_IS_LINUX)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    message(STATUS "Configuring on/for macOS")
    target_compile_definitions(Env PUBLIC "OS_IS_MACOSX")
    set(_OS_IS_XXX OS_IS_MACOSX)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message(STATUS "Configuring on/for Windows")
    target_compile_definitions(Env PUBLIC "OS_IS_WIN")
    set(_OS_IS_XXX OS_IS_WIN)
elseif(CMAKE_SYSTEM_NAME STREQUAL "AIX")
    message(STATUS "Configuring on/for IBM AIX")
    target_compile_definitions(Env PUBLIC "OS_IS_AIX")
    set(_OS_IS_XXX OS_IS_AIX)
else()
    message(STATUS "Configuring on/for ${CMAKE_SYSTEM_NAME}")
endif ()

foreach(key
    IN ITEMS
    NUMBER_OF_LOGICAL_CORES
    NUMBER_OF_PHYSICAL_CORES
    TOTAL_VIRTUAL_MEMORY
    AVAILABLE_VIRTUAL_MEMORY
    TOTAL_PHYSICAL_MEMORY
    AVAILABLE_PHYSICAL_MEMORY
    IS_64BIT
    HAS_FPU
    HAS_MMX
    HAS_MMX_PLUS
    HAS_SSE
    HAS_SSE2
    HAS_SSE_FP
    HAS_SSE_MMX
    HAS_AMD_3DNOW
    HAS_AMD_3DNOW_PLUS
    HAS_IA64
    OS_NAME
    OS_RELEASE
    OS_VERSION
    OS_PLATFORM
)
    cmake_host_system_information(RESULT _${key} QUERY ${key})
endforeach()

configure_file(env_config.h.in ${CMAKE_CURRENT_LIST_DIR}/include/Env/env_config.h @ONLY)