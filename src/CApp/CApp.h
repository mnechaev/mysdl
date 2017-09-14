#ifndef CAPP_H
#define CAPP_H

#include <SDL.h>
#include <SDL_events.h>
#include "../renders/Render.h"

class CApp {
public:
    CApp();
    ~CApp();
    int onExecute();

private:
    Render *renderer;

    bool running;
    unsigned step;

    bool init();

    void events(SDL_Event* event);
    void loop();
    void render();

    void cleanup();

//    void setPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b);
};

#endif

