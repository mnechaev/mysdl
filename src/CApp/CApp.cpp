#include "CApp.h"
#include "../utils/Benchmark.h"
#include "../utils/Logger.h"

#define S_W 640
#define S_H 480
#define S_XR 5
#define S_YR 5

CApp::CApp() {

    Logger::instance().on_instance_create("App");
    running = false;
    step = 0;
}

CApp::~CApp() {
    Logger::instance().on_instance_destroy("App");
}

int CApp::onExecute() {
    Logger::instance().info("Execute App...");
    if (!init()) {
        return -1;
    }

    sprite = new SimpleSprite();
    sprite->x = 100;
    sprite->y = 100;
    sprite->r = 30;
    Event *event = new Event();
    running = true;

    Benchmark benchmark;
    benchmark.init_on_frame(time_controller->get_ticks());
    while (running) {
        while (events_controller->check_event(event)) {
            events(event);
        }

        loop();
        render();

        benchmark.on_frame(time_controller->get_ticks());
    }

    delete event;

    cleanup();

    return 0;
}

bool CApp::init() {
    renderer = new Render(S_W, S_H);
    events_controller = new EventsController();
    time_controller = new TimeController();
    return renderer->init();
}


void CApp::events(Event *event) {
    if (event->type == EventTypes::QUIT) running = false;
    if (event->type == EventTypes::KEYDOWN) {
        switch (event->key) {
            case EventKeyCodes::UP: sprite->y -= S_H / S_YR / 4;
                break;
            case EventKeyCodes::DOWN: sprite->y += S_H / S_YR / 4;
                break;
            case EventKeyCodes::LEFT: sprite->x -= S_W / S_XR / 4;
                break;
            case EventKeyCodes::RIGHT: sprite->x += S_W / S_XR / 4;
                break;
        }
    }
}

void CApp::loop() {
    step++;

//    sprite->x +=sprite->dx;
//    sprite->y += sprite->dy;
    if (sprite->x >= renderer->width() - sprite->r * 2) sprite->dx = -1;
    if (sprite->y >= renderer->height() - sprite->r * 2) sprite->dy = -1;
    if (sprite->x <= 0) sprite->dx = 1;
    if (sprite->y <= 0) sprite->dy = 1;
    
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
            renderer->drawRect(r, renderer->color((uint8_t)((int)((x+y)*step*0.01) % 256), (uint8_t)((int)((x+2*y)*step*0.01) % 256), (uint8_t)((int)((2*x+y)*step*0.01) % 256)));
        }

    sprite->render(renderer);

    renderer->afterDraw();
}

void CApp::cleanup() {
    delete sprite;

    renderer->cleanup();
    delete renderer;
    renderer = nullptr;

    delete events_controller;
    events_controller = nullptr;

    delete time_controller;
    time_controller = nullptr;
}

//void CApp::setPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b) {
////    Uint32 *pixmem32;
////    Uint32 color;
////    color = SDL_MapRGB(surface->format, r, g, b);
////    pixmem32 = (Uint32*) surface->pixels + x + y*surface->pitch / 4;
////    *pixmem32 = color;
//}