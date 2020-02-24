//
// Created by mnechaev on 24.02.2020.
//

#include "SDLEventsControllerModel.h"
#include "../utils/Logger.h"


SDLEventsControllerModel::SDLEventsControllerModel() : IEventsControllerModel() {
    Logger::instance().on_instance_create("SDLEventsControllerModel");
}

SDLEventsControllerModel::~SDLEventsControllerModel() {
    Logger::instance().on_instance_destroy("SDLEventsControllerModel");
}

bool SDLEventsControllerModel::check_event(Event *event) {
    if (SDL_PollEvent(&sdl_event)) {
        event->type = EventTypes::NOEVENT;
        switch (sdl_event.type) {
            case SDL_QUIT:
                event->type = EventTypes::QUIT;
                break;
            case SDL_KEYDOWN:
                event->type = EventTypes::KEYDOWN;
                event->key = map_key();
                break;
            case SDL_KEYUP:
                event->type = EventTypes::KEYUP;
                event->key = map_key();
                break;
        }
        return true;
    }
    return false;
}

EventKeyCodes SDLEventsControllerModel::map_key() {
    switch (sdl_event.key.keysym.sym) {
        case SDLK_UP:
            return EventKeyCodes::UP;;
        case SDLK_DOWN:
            return EventKeyCodes::DOWN;
        case SDLK_LEFT:
            return EventKeyCodes::LEFT;
        case SDLK_RIGHT:
            return EventKeyCodes::RIGHT;
    }

    return EventKeyCodes::UNKNOWN;
}
