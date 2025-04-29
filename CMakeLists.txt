set(OpenCV_DIR "C:/OpenCV/build")  # там где лежит opencv4Config.cmake
find_package(OpenCV REQUIRED)
cmake_minimum_required(VERSION 3.10)
project(fifth)
set(CMAKE_CXX_STANDARD 17)

# 1) Находим OpenCV
find_package(OpenCV REQUIRED)

# 2) Опционально — OpenMP для директив #pragma omp
find_package(OpenMP)
if(OpenMP_CXX_FOUND)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

include_directories(${OpenCV_INCLUDE_DIRS})

# 3) Цель: blur (работа с изображениями)
add_executable(blur fifth/blur.cpp)
target_link_libraries(blur ${OpenCV_LIBS})

# 4) Цель: atomic_example (пример mutex vs atomic)
add_executable(atomic_example fifth/atomic_example.cpp)
if(OpenMP_CXX_FOUND)
  target_link_libraries(atomic_example OpenMP::OpenMP_CXX)
endif()
