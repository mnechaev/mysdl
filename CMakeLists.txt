cmake_minimum_required(VERSION 3.8)
project(mysdl)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/CApp/CApp.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
