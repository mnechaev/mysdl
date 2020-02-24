//
// Created by Mikhail Nechaev on 14/09/17.
//

#include <SDL.h>
#include <iostream>
#include <cmath>
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

void SDLRenderModel::setPixel(int16_t x, int16_t y, uint32_t color) {
    if (x < 0 || y < 0 || x > width() || y >= height()) return;

    uint32_t *pixmem32;
    pixmem32 = (Uint32*) surface->pixels + y*surface->pitch / 4 + x;
    *pixmem32 = color;
}

void SDLRenderModel::drawCircle(RRect &rect, uint32_t color) {
    int16_t r = (int16_t) (rect.w / 2);
    int16_t rr = r * r;
    for (int16_t x = -r; x < r; x++)
        for (int16_t y = -r; y < r; y++) {
            if (x*x + x + y*y + y - rr <= 1) setPixel(x + rect.x + r, y + rect.y + r, color);
        }
}
