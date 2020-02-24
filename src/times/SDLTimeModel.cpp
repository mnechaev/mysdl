//
// Created by mnechaev on 24.02.2020.
//

#include <SDL_timer.h>
#include "SDLTimeModel.h"
#include "../utils/Logger.h"

SDLTimeModel::SDLTimeModel() {
    Logger::instance().on_instance_create("SDLTimeModel");
}

uint32_t SDLTimeModel::get_ticks() {
    return SDL_GetTicks();
}

SDLTimeModel::~SDLTimeModel() {
    Logger::instance().on_instance_destroy("SDLTimeModel");
}
