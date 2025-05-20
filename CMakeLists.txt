cmake_minimum_required(VERSION 3.10)
project(StrategyPatternLab)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(${CMAKE_SOURCE_DIR}/labs/sixth)

file(GLOB SOURCE_FILES
    "${CMAKE_SOURCE_DIR}/labs/sixth/*.cpp"
)

file(GLOB HEADER_FILES
    "${CMAKE_SOURCE_DIR}/labs/sixth/*.h"
)


add_executable(StrategyPatternLab
    ${SOURCE_FILES}
    ${HEADER_FILES}
)