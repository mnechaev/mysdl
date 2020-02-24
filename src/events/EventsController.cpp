//
// Created by mnechaev on 24.02.2020.
//

#include <iostream>
#include "EventsController.h"

EventsController::EventsController(IEventsControllerModel *events_model): _events_model(events_model) {
    std::cout << "Create EventsController..." << std::endl;
}

EventsController::~EventsController() {
    delete _events_model;
    std::cout << "Destroy EventsController..." << std::endl;
}

bool EventsController::check_event(Event *event) {
    return _events_model->check_event(event);
}
