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
        easy/9.h
        easy/13.h
        easy/14.h
        easy/20.h
        easy/21.h
        easy/26.h
        easy/27.h
        easy/28.h
        easy/35.h
)

# 一般难度的题目
set(MEDIUM_SOURCES
        medium/2.h
        medium/3.h
        medium/5.h
        medium/6.h
        medium/7.h
        medium/8.h
        medium/11.h
        medium/12.h
        medium/15.h
        medium/16.h
        medium/17.h
        medium/18.h
        medium/19.h
        medium/22.h
        medium/24.h
        medium/29.h
        medium/31.h
        medium/33.h
        medium/34.h
        medium/36.h
        medium/38.h
        medium/39.h
        medium/40.h
        medium/43.h
        medium/45.h
        medium/46.h
)

# 困难难度的题目
set(HARD_SOURCES
        hard/4.h
        hard/10.h
        hard/23.h

        hard/25.h
        hard/30.h
)

add_executable(algorithm_test
        ${EASY_SOURCES}
        ${MEDIUM_SOURCES}
        ${HARD_SOURCES}
        src/Application.cpp
        test/test.h
        utils/utils.h)