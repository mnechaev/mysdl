#ifndef CAPP_H
#define CAPP_H

#include <vector>
#include "../renders/Render.h"
#include "SimpleSprite.h"
#include "../events/EventsController.h"
#include "../times/TimeController.h"

class CApp {
public:
    CApp();
    ~CApp();
    int onExecute();

private:
    Render *renderer;
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

    void loop_sprite(SimpleSprite* sprite);

    void cleanup();
};

#endif

