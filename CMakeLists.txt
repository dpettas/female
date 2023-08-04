cmake_minimum_required(VERSION 3.0.0)
project(FEMALE VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_BUILD_TYPE "Release")


add_executable(FEMALE ./src/main.cpp)

include(CPack)
