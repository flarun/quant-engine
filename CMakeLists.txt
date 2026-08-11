cmake_minimum_required(VERSION 3.20)
project(quant_engine CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(quant_engine src/main.cpp)
target_compile_definitions(quant_engine PRIVATE PROJECT_SOURCE_DIR="${CMAKE_SOURCE_DIR}")