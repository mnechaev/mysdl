#ifndef CAPP_H
#define CAPP_H

#include <vector>
#include "SimpleSprite.h"
#include "../events/EventsController.h"
#include "../times/TimeController.h"
#include "../render/IRenderable.h"
#include "../render/ICanvasController.h"
#include "../render/IRenderOwner.h"
#include "../render/Cache.h"

class CApp {
public:
    CApp();
    ~CApp();
    int onExecute();

private:
    ICanvasController *canvas_controller;
    Cache *cache;
    EventsController *events_controller;
    TimeController *time_controller;

    SimpleSprite *sprite;
    std::vector<SimpleSprite*> objects;

    bool running;
    unsigned step;

    bool init();

    void events(Event *event);
    void loop();
    void render();
    void render_object(IRenderOwner *object);

    void loop_sprite(SimpleSprite* sprite);

    void cleanup();
};

#endif

