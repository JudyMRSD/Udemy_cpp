cmake_minimum_required(VERSION 3.12)
project(1_Exceptions)

set(CMAKE_CXX_STANDARD 14)

# add_executable(1_Exceptions basicExceptions.cpp)
# add_executable(1_Exceptions StandardExceptions.cpp)
# add_executable(1_Exceptions CustomExceptions.cpp)
add_executable(1_Exceptions CatchSubclassExceptions.cpp)
