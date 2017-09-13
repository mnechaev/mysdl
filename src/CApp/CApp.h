#ifndef CAPP_H
#define CAPP_H

class CApp {
public:
    CApp();
    ~CApp();
    int onExecute();

private:
    bool running = false;
    unsigned step = 0;

    bool init();

    void events();
    void loop();
    void render();

    void cleanup();
};

#endif

