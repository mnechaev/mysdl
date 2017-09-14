//
// Created by Mikhail Nechaev on 14/09/17.
//

#include <SDL.h>
#include <iostream>
#include "SDLRenderModel.h"

SDLRenderModel::SDLRenderModel(int width, int height) : IRenderModel(width, height) {
    std::cout << "Create SDLRenderModel..." << std::endl;
}

SDLRenderModel::~SDLRenderModel() {
    std::cout << "Destroy SDLRenderModel..." << std::endl;
}

bool SDLRenderModel::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    if ((surface = SDL_SetVideoMode(width(), height(), 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == nullptr) {
        return false;
    }

    return true;
}

void SDLRenderModel::cleanup() {
    SDL_Quit();
}

bool SDLRenderModel::beforeDraw() {
    if(SDL_MUSTLOCK(surface)) {
        if(SDL_LockSurface(surface) < 0) return false;
    }

    return true;
}

void SDLRenderModel::afterDraw() {
    if(SDL_MUSTLOCK(surface)) SDL_UnlockSurface(surface);
    SDL_Flip(surface);
}

uint32_t SDLRenderModel::color(uint8_t r, uint8_t g, uint8_t b) {
    return SDL_MapRGB(surface->format, r, g, b);
}

void SDLRenderModel::drawRect(RRect &rect, uint32_t color) {
    SDL_Rect r{};
    r.x = rect.x;
    r.y = rect.y;
    r.w = rect.w;
    r.h = rect.h;
    SDL_FillRect(surface, &r, color);
}
