//
// Created by mnechaev on 12.03.2020.
//

#ifndef MYSDL_IDRAWABLE_H
#define MYSDL_IDRAWABLE_H

#include "../render/ICanvas.h"

class IDrawable {
public:
    virtual void process_draw(ICanvas *canvas, int16_t x_offset, int16_t y_offset) = 0;
    virtual ~IDrawable() = default;
};

#endif //MYSDL_IDRAWABLE_H
