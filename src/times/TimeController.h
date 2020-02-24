//
// Created by mnechaev on 24.02.2020.
//

#ifndef MYSDL_TIMECONTROLLER_H
#define MYSDL_TIMECONTROLLER_H


#include "ITimeModel.h"

class TimeController {
public:
    TimeController();
    ~TimeController();

    uint32_t get_ticks();
private:
    ITimeModel *time_model;
};


#endif //MYSDL_TIMECONTROLLER_H
