#include "CApp.h"
#include "../renders/SDLRenderModel.h"
#include <iostream>

#define S_W 640
#define S_H 480
#define S_XR 5
#define S_YR 5

CApp::CApp() {
    std::cout << "Create App..." << std::endl;
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

    sprite = new SimpleSprite();
    sprite->x = 100;
    sprite->y = 100;
    sprite->r = 30;
    SDL_Event event{};

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
    renderer = new Render(new SDLRenderModel(S_W, S_H));
    return renderer->init();
}

void CApp::events(SDL_Event* event) {
    if (event->type == SDL_QUIT) running = false;
    if (event->type == SDL_KEYDOWN) step = 0;
}

void CApp::loop() {
    step++;

    sprite->x += 1;
    sprite->y += 1;
    if (sprite->x >= renderer->width() - 30) sprite->x = 0;
    if (sprite->y >= renderer->height() - 30) sprite->y = 0;
}

void CApp::render() {
    if (!renderer->beforeDraw()) return;

    RRect r{};
    r.w = S_W/S_XR;
    r.h = S_H/S_YR;
    for (uint x = 0; x < S_XR; x++)
        for (uint y = 0; y < S_YR; y++) {
            r.x = (int16_t)(x * r.w);
            r.y = (int16_t)(y * r.h);
            renderer->drawRect(r, renderer->color((uint8_t)(((x+y + 1)*step) % 256), (uint8_t)(((x+2*y)*step) % 256), (uint8_t)(((2*x+y)*step) % 256)));
        }

    sprite->render(renderer);

    renderer->afterDraw();
}

void CApp::cleanup() {
    delete sprite;

    renderer->cleanup();
    delete renderer;
    renderer = nullptr;
}

//void CApp::setPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b) {
////    Uint32 *pixmem32;
////    Uint32 color;
////    color = SDL_MapRGB(surface->format, r, g, b);
////    pixmem32 = (Uint32*) surface->pixels + x + y*surface->pitch / 4;
////    *pixmem32 = color;
//}