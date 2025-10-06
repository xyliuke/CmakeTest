
set(SRC
        One.cpp
)

add_library(OneModule ${SRC})

target_include_directories(OneModule
        PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include
)

