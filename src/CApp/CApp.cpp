#include <cmath>
#include "CApp.h"
#include "../utils/Benchmark.h"
#include "../utils/Logger.h"
#include "../render/IRenderOwner.h"
#include "../sdl_support/render/SDLCanvasController.h"

#define S_W 640
#define S_H 480
#define S_XR 5
#define S_YR 5

CApp::CApp() {

    Logger::instance()->on_instance_create("App");
    running = false;
    step = 0;
}

CApp::~CApp() {
    Logger::instance()->on_instance_destroy("App");
}

int CApp::onExecute() {
    Logger::instance()->info("Execute App...");
    if (!init()) {
        return -1;
    }

    sprite = SimpleSprite::create();
    sprite->x = 100 * SS_COORD_SCALE;
    sprite->y = 100 * SS_COORD_SCALE;
    sprite->r = 30;
    Event *event = new Event();

    for (uint i = 0; i < 10000; i++) {
        SimpleSprite::pointer obj = SimpleSprite::create();
        obj->x = random() % S_W * SS_COORD_SCALE;
        obj->y = random() % S_H * SS_COORD_SCALE;
        obj->r = random()%30 + 10;
        obj->dx = random()%2 == 0 ? -1 : 1;
        obj->dy = random()%2 == 0 ? -1 : 1;
        objects.push_back(obj);
    }


    running = true;

    Benchmark benchmark;
    benchmark.init_on_frame(time_controller->get_ticks());
    uint32_t t = time_controller->get_ticks();
    while (running) {
        while (events_controller->check_event(event)) {
            events(event);
        }

        uint32_t ct = time_controller->get_ticks();
        uint32_t dt = ct - t;
        if (dt < min_ft()) continue;

        loop(dt);
        render();

        benchmark.on_frame(time_controller->get_ticks());
        t = ct;
    }

    delete event;

    cleanup();

    return 0;
}

bool CApp::init() {
    canvas_controller = new SDLCanvasController(S_W, S_H);
    if (!canvas_controller->init()) return false;

    cache = new Cache(canvas_controller);

    events_controller = new EventsController();
    time_controller = new TimeController();
    return true;
}


void CApp::events(Event *event) {
    if (event->type == EventTypes::QUIT) running = false;
    if (event->type == EventTypes::KEYDOWN) {
        switch (event->key) {
            case EventKeyCodes::UP: sprite->y -= 1 * SS_COORD_SCALE;
                break;
            case EventKeyCodes::DOWN: sprite->y += 1 * SS_COORD_SCALE;
                break;
            case EventKeyCodes::LEFT: sprite->x -= 1 * SS_COORD_SCALE;
                break;
            case EventKeyCodes::RIGHT: sprite->x += 1 * SS_COORD_SCALE;
                break;
            case EventKeyCodes::SPACE:
                sprite->r += 5;
                if (sprite->r > 40) sprite->r = 30;
                sprite->invalidate_cache();
                break;
            case EventKeyCodes::RETURN:
                sprite->color_index++;
                if (sprite->color_index >= 3) sprite->color_index = 0;
                sprite->invalidate_cache();
                break;
        }
    }
}

#define APP_STEP_SPEED 2500

void CApp::loop(uint32_t dt) {
    step += (int) APP_STEP_SPEED * dt / 1000;

    for(auto sprite : objects) {
        loop_sprite(sprite.get(), dt);
    }
}

void CApp::loop_sprite(SimpleSprite *sprite, uint32_t dt) {
    sprite->x += (float) sprite->dx * SS_REAL_SPEED * SS_COORD_SCALE * dt / 1000;
    sprite->y += (float) sprite->dy * SS_REAL_SPEED * SS_COORD_SCALE * dt / 1000;
    if (sprite->x / SS_COORD_SCALE >= canvas_controller->main_canvas()->width() - sprite->r * 2) sprite->dx = -1;
    if (sprite->y / SS_COORD_SCALE >= canvas_controller->main_canvas()->height() - sprite->r * 2) sprite->dy = -1;
    if (sprite->x <= 0) sprite->dx = 1;
    if (sprite->y <= 0) sprite->dy = 1;
}

void CApp::render() {
    if (!canvas_controller->beforeDraw()) return;

    RRect r{};
    r.w = S_W/S_XR;
    r.h = S_H/S_YR;
    for (uint x = 0; x < S_XR; x++)
        for (uint y = 0; y < S_YR; y++) {
            r.x = (int16_t)(x * r.w);
            r.y = (int16_t)(y * r.h);
            canvas_controller->main_canvas()->drawRect(r, canvas_controller->main_canvas()->color((uint8_t)((int)((x+y)*step*0.01) % 256), (uint8_t)((int)((x+2*y)*step*0.01) % 256), (uint8_t)((int)((2*x+y)*step*0.01) % 256)));
        }

    for (auto s : objects) render_object(s.get());
    render_object(sprite.get());

    canvas_controller->afterDraw();
}

void CApp::render_object(IRenderOwner *object) {
    IRenderable *renderable = object->render();

    ICanvas *cached = cache->get_from_cache(object->cache_key());
    if (cached == nullptr) {
        cached = cache->create_cached(object->cache_key(), renderable->render_width(), renderable->render_height());
        renderable->render(cached, 0, 0);
    }

    canvas_controller->main_canvas()->drawCanvas(cached, renderable->render_x(), renderable->render_y());
}

void CApp::cleanup() {
    delete cache;
    cache = nullptr;

    canvas_controller->cleanup();
    delete canvas_controller;
    canvas_controller = nullptr;

    delete events_controller;
    events_controller = nullptr;

    delete time_controller;
    time_controller = nullptr;
}

uint16_t CApp::min_ft() {
    return ceil(1000.0 / max_fps);
}
