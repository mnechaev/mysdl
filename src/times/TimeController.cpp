//
// Created by mnechaev on 24.02.2020.
//

#include "TimeController.h"
#include "../sdl_support/time/SDLTimeModel.h"
#include "../utils/Logger.h"

TimeController::TimeController() {
    Logger::instance()->on_instance_create("TimeController");
    time_model = new SDLTimeModel();
}

TimeController::~TimeController() {
    delete time_model;
    time_model = nullptr;

    Logger::instance()->on_instance_destroy("TimeController");
}

uint32_t TimeController::get_ticks() {
    return time_model->get_ticks();
}
