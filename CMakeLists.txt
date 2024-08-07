cmake_minimum_required(VERSION 3.26)
project(algorithm_test)

set(CMAKE_CXX_STANDARD 17)

# 设置头文件路径
set(EASY_LIB easy)
set(MEDIUM_LIB medium)
set(HARD_LIB hard)
# 添加头文件路径
include_directories(
        ${EASY_LIB}
        ${MEDIUM_LIB}
        ${HARD_LIB})

# 简单难度的题目
set(EASY_SOURCES
        easy/1.h

)

# 一般难度的题目
set(MEDIUM_SOURCES
        medium/2.h
)

# 困难难度的题目
set(HARD_SOURCES
)

add_executable(algorithm_test
        ${EASY_SOURCES}
        ${MEDIUM_SOURCES}
        ${HARD_SOURCES}
        src/Application.cpp)