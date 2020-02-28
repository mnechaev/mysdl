//
// Created by mnechaev on 24.02.2020.
//

#ifndef MYSDL_SDLTIMEMODEL_H
#define MYSDL_SDLTIMEMODEL_H


#include "../../times/ITimeModel.h"

class SDLTimeModel : public ITimeModel {
public:
    SDLTimeModel();

    uint32_t get_ticks() override;

    ~SDLTimeModel() override;
};


#endif //MYSDL_SDLTIMEMODEL_H
