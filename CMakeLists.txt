cmake_minimum_required(VERSION 3.6)   # CMake version check
project(Compiler)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 11)            # Enable c++11 standard


file(GLOB SOURCE_FILES
    "ClassLib/ParserNodes/*.cpp"
    "Main.cpp"
    "ClassLib/*.cpp"
)

add_executable(Compiler ${SOURCE_FILES})       # Add executable target with source files listed in SOURCE_FILES variable