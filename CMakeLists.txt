cmake_minimum_required(VERSION 3.10)
project(labs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(memory_leak_demo labs/third/memory_leak.cpp)
add_executable(unique_ptr_demo labs/third/unique_ptr_demo.cpp)
add_executable(shared_ptr_demo labs/third/shared_ptr_demo.cpp)
add_executable(weak_ptr_demo labs/third/weak_ptr_demo.cpp)
add_executable(move_semantics_lab labs/forth/main.cpp)
# Find OpenCV for image loading and saving
find_package(OpenCV REQUIRED)

# Optional: Find OpenMP for compiler directives
find_package(OpenMP)
if(OpenMP_CXX_FOUND)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

include_directories(${OpenCV_INCLUDE_DIRS})

# Executable for image blur
add_executable(blur src/blur.cpp)
target_link_libraries(blur ${OpenCV_LIBS})

# Executable for atomic operations example
add_executable(atomic_example src/atomic_example.cpp)
if(OpenMP_CXX_FOUND)
  target_link_libraries(atomic_example OpenMP::OpenMP_CXX)
endif()
