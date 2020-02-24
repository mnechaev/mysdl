cmake_minimum_required(VERSION 3.8)
project(mysdl)

set(CMAKE_CXX_STANDARD 11)

find_package(SDL REQUIRED)
include_directories(${SDL_INCLUDE_DIR})

set(SOURCE_FILES src/main.cpp src/CApp/CApp.cpp src/renders/IRenderModel.h src/renders/Render.cpp src/renders/Render.h src/renders/SDLRenderModel.cpp src/renders/SDLRenderModel.h src/CApp/SimpleSprite.cpp src/CApp/SimpleSprite.h src/events/Event.h src/events/IEventsControllerModel.h src/events/SDLEventsControllerModel.cpp src/events/SDLEventsControllerModel.h src/events/EventsController.cpp src/events/EventsController.h src/utils/Benchmark.cpp src/utils/Benchmark.h src/times/ITimeModel.h src/times/SDLTimeModel.cpp src/times/SDLTimeModel.h src/times/TimeController.cpp src/times/TimeController.h src/utils/Logger.cpp src/utils/Logger.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL_LIBRARY})
