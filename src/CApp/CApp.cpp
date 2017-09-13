#include "CApp.h"
#include <iostream>

CApp::CApp() {
    std::cout << "Create App..." << std::endl;
}

CApp::~CApp() {
    std::cout << "Destroy App..." << std::endl;
}

int CApp::onExecute() {
    std::cout << "Execute App..." << std::endl;
    if (!init()) {
        return -1;
    }

    running = true;

    while (running) {
        events();
        loop();
        render();
    }

    cleanup();

    return 0;
}

bool CApp::init() {
    return true;
}

void CApp::events() {
    if (step >= 10) running = false;
}

void CApp::loop() {
    step++;
}

void CApp::render() {
    std::cout << "Render " << step << std::endl;
}

void CApp::cleanup() {

}
