cmake_minimum_required(VERSION 3.20)
project(quant_engine CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(quant_core STATIC
    src/core/CsvLoader.cpp
)
target_include_directories(quant_core PUBLIC src/core)

add_executable(quant_engine_cli src/cli/main.cpp)
target_link_libraries(quant_engine_cli PRIVATE quant_core)
target_compile_definitions(quant_engine_cli PRIVATE PROJECT_SOURCE_DIR="${CMAKE_SOURCE_DIR}")