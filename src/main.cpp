#include <SDL.h>
#include "CApp/CApp.h"
#include "utils/Logger.h"

int main(int argc, char *argv[]) {
    CApp *app = new CApp;

    int result = app->onExecute();

    delete app;

    Logger::instance()->result();

    return result;
}
