//
// Created by mnechaev on 28.02.2020.
//

#include <SDL_video.h>
#include <SDL.h>
#include "SDLCanvasController.h"
#include "SDLCanvas.h"
#include "../../utils/Logger.h"

SDLCanvasController::SDLCanvasController(uint16_t width, uint16_t height):_width(width),
                                                                          _height(height) {
    Logger::instance()->on_instance_create("SDLCanvasController");
}

SDLCanvasController::~SDLCanvasController() {
    Logger::instance()->on_instance_destroy("SDLCanvasController");
}

ICanvas *SDLCanvasController::create_canvas(uint16_t width, uint16_t height) {
    SDL_Surface *screen = main->image();
    SDL_Surface *image = SDL_CreateRGBSurface(SDL_HWSURFACE, width, height,
                                              screen->format->BitsPerPixel,
                                              screen->format->Rmask,
                                              screen->format->Gmask,
                                              screen->format->Bmask,
                                              screen->format->Amask);

    return new SDLCanvas(image, width, height);
}

void SDLCanvasController::destroy_canvas(ICanvas *canvas) {
    destroy_sdl_canvas((SDLCanvas *) canvas);
}

void SDLCanvasController::destroy_sdl_canvas(SDLCanvas *canvas) {
    SDL_FreeSurface(canvas->image());
    delete canvas;
}

bool SDLCanvasController::init() {
    SDL_Surface *surface;
    if ((surface = SDL_SetVideoMode(_width, _height, BPP, SDL_HWSURFACE | SDL_DOUBLEBUF)) == nullptr) {
        return false;
    }

    main = new SDLCanvas(surface, _width, _height);
    return true;
}

void SDLCanvasController::cleanup() {
    destroy_canvas(main);
    SDL_Quit();
}

bool SDLCanvasController::beforeDraw() {
    SDL_Surface *surface = main->image();

    if(SDL_MUSTLOCK(surface)) {
        if(SDL_LockSurface(surface) < 0) return false;
    }

    return true;
}

void SDLCanvasController::afterDraw() {
    SDL_Surface *surface = main->image();

    if(SDL_MUSTLOCK(surface)) SDL_UnlockSurface(surface);
    SDL_Flip(surface);
}

uint32_t SDLCanvasController::color(uint8_t r, uint8_t g, uint8_t b) {
    return SDL_MapRGB(main->image()->format, r, g, b);
}

ICanvas *SDLCanvasController::main_canvas() {
    return main;
}
