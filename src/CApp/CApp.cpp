#include "CApp.h"
#include <iostream>

CApp::CApp() {
    std::cout << "Create App..." << std::endl;
    surface = nullptr;
    running = false;
    step = 0;
}

CApp::~CApp() {
    std::cout << "Destroy App..." << std::endl;
}

int CApp::onExecute() {
    std::cout << "Execute App..." << std::endl;
    if (!init()) {
        return -1;
    }

    SDL_Event event;

    running = true;

    while (running) {
        while(SDL_PollEvent(&event)) {
            events(&event);
        }

        loop();
        render();
    }

    cleanup();

    return 0;
}

bool CApp::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    if ((surface = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == nullptr) {
        return false;
    }

    return true;
}

void CApp::events(SDL_Event* event) {
    if (event->type == SDL_QUIT) running = false;
    if (event->type == SDL_KEYDOWN) step = 1;
}

void CApp::loop() {
//    step++;
}

void CApp::render() {
    std::cout << "Render\t" << step << std::endl;

    if(SDL_MUSTLOCK(surface)) {
        if(SDL_LockSurface(surface) < 0) return;
    }

    if (step == 1) {
        step = 0;
        Uint32 *pixmem32;
        pixmem32 = (Uint32*) surface->pixels;
        Uint32 color = SDL_MapRGB(surface->format, 0, 0, 0);
        for (Uint32 i = 0; i < 640 * 480; i++) *(pixmem32+i) = color;
    }

    setPixel(rand() % 640, rand() % 480, rand() % 256, rand() % 256, rand() % 256);
    setPixel(rand() % 640, rand() % 480, rand() % 256, rand() % 256, rand() % 256);
    setPixel(rand() % 640, rand() % 480, rand() % 256, rand() % 256, rand() % 256);
    setPixel(rand() % 640, rand() % 480, rand() % 256, rand() % 256, rand() % 256);
    setPixel(rand() % 640, rand() % 480, rand() % 256, rand() % 256, rand() % 256);
    setPixel(rand() % 640, rand() % 480, rand() % 256, rand() % 256, rand() % 256);
    setPixel(rand() % 640, rand() % 480, rand() % 256, rand() % 256, rand() % 256);
    setPixel(rand() % 640, rand() % 480, rand() % 256, rand() % 256, rand() % 256);
    setPixel(rand() % 640, rand() % 480, rand() % 256, rand() % 256, rand() % 256);
    setPixel(rand() % 640, rand() % 480, rand() % 256, rand() % 256, rand() % 256);
    setPixel(rand() % 640, rand() % 480, rand() % 256, rand() % 256, rand() % 256);
    setPixel(rand() % 640, rand() % 480, rand() % 256, rand() % 256, rand() % 256);

    if(SDL_MUSTLOCK(surface)) SDL_UnlockSurface(surface);
    SDL_Flip(surface);
}

void CApp::cleanup() {
    SDL_Quit();
}

void CApp::setPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b) {
    Uint32 *pixmem32;
    Uint32 color;
    color = SDL_MapRGB(surface->format, r, g, b);
    pixmem32 = (Uint32*) surface->pixels + x + y*surface->pitch / 4;
    *pixmem32 = color;
}
