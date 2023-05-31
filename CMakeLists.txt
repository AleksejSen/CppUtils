cmake_minimum_required(VERSION 3.5)

project(CodeTest)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(app)
#To add Library: 
#add_subdirectory(libName)
add_subdirectory(Utilities)
