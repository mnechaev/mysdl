//
// Created by mnechaev on 24.02.2020.
//

#ifndef MYSDL_EVENTSCONTROLLER_H
#define MYSDL_EVENTSCONTROLLER_H


#include "IEventsControllerModel.h"

class EventsController {
public:
    explicit EventsController();
    ~EventsController();

    bool check_event(Event *event);

private:
    IEventsControllerModel *_events_model;
};


#endif //MYSDL_EVENTSCONTROLLER_H
