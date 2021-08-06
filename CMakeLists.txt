cmake_minimum_required(VERSION 3.19)
project(async)

set(CMAKE_CXX_STANDARD 11)

add_executable(common common.cpp)
add_executable(threads threads.cpp)
add_executable(async async.cpp)
add_executable(packaged_task packaged_task.cpp)
add_executable(promise promise.cpp)