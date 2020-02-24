//
// Created by mnechaev on 24.02.2020.
//

#ifndef MYSDL_ITIMEMODEL_H
#define MYSDL_ITIMEMODEL_H


#include <cstdint>

class ITimeModel {
public:
    virtual uint32_t get_ticks() = 0;
    virtual ~ITimeModel() = default;
};


#endif //MYSDL_ITIMEMODEL_H
