cmake_minimum_required(VERSION 3.8)
project(CPUScheduler)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Process.cpp Process.h Scheduler.cpp Scheduler.h FileUtil.cpp FileUtil.h Utils.h)
add_executable(CPUScheduler ${SOURCE_FILES})