//
// Created by mnechaev on 24.02.2020.
//

#ifndef MYSDL_IEVENTSCONTROLLERMODEL_H
#define MYSDL_IEVENTSCONTROLLERMODEL_H


#include "Event.h"

class IEventsControllerModel {
public:
    virtual bool check_event(Event *event) = 0;
    virtual ~IEventsControllerModel() = default;
};


#endif //MYSDL_IEVENTSCONTROLLERMODEL_H
