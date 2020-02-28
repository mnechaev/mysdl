//
// Created by mnechaev on 24.02.2020.
//

#include "EventsController.h"
#include "../sdl_support/events/SDLEventsControllerModel.h"
#include "../utils/Logger.h"

EventsController::EventsController() {
    Logger::instance()->on_instance_create("EventsController");
    _events_model = new SDLEventsControllerModel();
}

EventsController::~EventsController() {
    delete _events_model;
    _events_model = nullptr;

    Logger::instance()->on_instance_destroy("EventsController");
}

bool EventsController::check_event(Event *event) {
    return _events_model->check_event(event);
}
