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
}

void CApp::loop() {
    step++;
}

void CApp::render() {
    std::cout << "Render\t" << step << std::endl;
}

void CApp::cleanup() {
    SDL_Quit();
}
