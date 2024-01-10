cmake_minimum_required(VERSION 3.10)

project(Workshop)

add_compile_options(-std=c++20)

add_executable(Workshop 
    main.cpp
)

target_link_libraries(Workshop -lmingw32)

target_include_directories(Workshop
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../
)