cmake_minimum_required(VERSION 3.16)
project(hw1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    add_compile_options(/utf-8 /W4 /wd4100)
else()
    add_compile_options(-Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field)
endif()

add_executable(test_queue test_queue.cpp queue.cpp)

enable_testing()
add_test(NAME p2_queue COMMAND test_queue p2)
add_test(NAME p4_optional COMMAND test_queue p4)
