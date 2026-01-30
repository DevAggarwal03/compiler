
cmake_minimum_required(VERSION 3.13)
project(bottle)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Define source files
set(SOURCE_FILES src/main.cpp)

# Create executable target
add_executable(bottle ${SOURCE_FILES})   
