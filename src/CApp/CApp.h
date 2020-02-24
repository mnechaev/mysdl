#ifndef CAPP_H
#define CAPP_H

#include "../renders/Render.h"
#include "SimpleSprite.h"
#include "../events/EventsController.h"

class CApp {
public:
    CApp();
    ~CApp();
    int onExecute();

private:
    Render *renderer;
    EventsController *events_controller;

    SimpleSprite *sprite;

    bool running;
    unsigned step;

    bool init();

    void events(Event *event);
    void loop();
    void render();

    void cleanup();
};

#endif

