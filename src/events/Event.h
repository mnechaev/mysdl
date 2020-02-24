//
// Created by mnechaev on 24.02.2020.
//

#ifndef MYSDL_EVENT_H
#define MYSDL_EVENT_H

#include <cstdint>

enum EventTypes {
    NOEVENT = 0,
    QUIT = 1,
    KEYDOWN,
    KEYUP
};

enum EventKeyCodes {
    UNKNOWN = 0,
    UP = 273,
    DOWN = 274,
    RIGHT = 275,
    LEFT = 276
};

class Event {
public:
    EventTypes type;
    EventKeyCodes key;
};


#endif //MYSDL_EVENT_H
