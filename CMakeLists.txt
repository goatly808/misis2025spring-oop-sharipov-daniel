cmake_minimum_required(VERSION 3.10)
project(MemoryManagement)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(memory_leak_demo labs/third/memory_leak.cpp)
add_executable(unique_ptr_demo labs/third/unique_ptr_demo.cpp)
add_executable(shared_ptr_demo labs/third/shared_ptr_demo.cpp)
add_executable(weak_ptr_demo labs/third/weak_ptr_demo.cpp)