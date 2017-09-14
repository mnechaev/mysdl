cmake_minimum_required(VERSION 3.8)
project(mysdl)

set(CMAKE_CXX_STANDARD 11)

include_directories(${SDL_INCLUDE_DIR})

set(SOURCE_FILES src/main.cpp src/CApp/CApp.cpp src/renders/IRenderModel.cpp src/renders/IRenderModel.h src/renders/Render.cpp src/renders/Render.h src/renders/SDLRenderModel.cpp src/renders/SDLRenderModel.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL_LIBRARY})
