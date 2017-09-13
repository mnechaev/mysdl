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
    running = true;

    while (running) {
        events();
        loop();
        render();
    }

    return 0;
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
