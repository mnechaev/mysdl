cmake_minimum_required(VERSION 3.8)
project(mysdl)

set(CMAKE_CXX_STANDARD 11)

find_package(SDL REQUIRED)
include_directories(${SDL_INCLUDE_DIR})

set(SOURCE_FILES src/main.cpp src/CApp/CApp.cpp src/CApp/SimpleSprite.cpp src/CApp/SimpleSprite.h src/events/Event.h src/events/IEventsControllerModel.h src/sdl_support/events/SDLEventsControllerModel.cpp src/sdl_support/events/SDLEventsControllerModel.h src/events/EventsController.cpp src/events/EventsController.h src/utils/Benchmark.cpp src/utils/Benchmark.h src/times/ITimeModel.h src/sdl_support/time/SDLTimeModel.cpp src/sdl_support/time/SDLTimeModel.h src/times/TimeController.cpp src/times/TimeController.h src/utils/Logger.cpp src/utils/Logger.h src/render/IRenderable.h src/render/renders.h src/sdl_support/render/SDLCanvas.cpp src/sdl_support/render/SDLCanvas.h src/render/ICanvas.h src/render/ICanvasController.h src/sdl_support/render/SDLCanvasController.cpp src/sdl_support/render/SDLCanvasController.h src/render/IRenderOwner.h src/CApp/SimpleSpriteRender.cpp src/CApp/SimpleSpriteRender.h src/render/Cache.cpp src/render/Cache.h src/scenes/ISceneObject.h src/scenes/ITickableObject.h src/scenes/Scene.cpp src/scenes/Scene.h src/scenes/SceneObjectsCollection.h src/scenes/IDrawable.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL_LIBRARY})
