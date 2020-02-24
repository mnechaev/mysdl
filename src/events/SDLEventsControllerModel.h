//
// Created by mnechaev on 24.02.2020.
//

#ifndef MYSDL_SDLEVENTSCONTROLLERMODEL_H
#define MYSDL_SDLEVENTSCONTROLLERMODEL_H


#include <SDL_events.h>
#include "IEventsControllerModel.h"

class SDLEventsControllerModel : public IEventsControllerModel {
public:
    SDLEventsControllerModel();
    ~SDLEventsControllerModel() override;
    bool check_event(Event *event) override;
private:
    SDL_Event sdl_event;

    EventKeyCodes map_key();
};


#endif //MYSDL_SDLEVENTSCONTROLLERMODEL_H
