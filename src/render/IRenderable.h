//
// Created by mnechaev on 26.02.2020.
//

#ifndef MYSDL_IRENDERABLE_H
#define MYSDL_IRENDERABLE_H

#include <string>
#include "ICanvas.h"

class IRenderable {
public:
    virtual int render_x() const = 0;
    virtual int render_y() const = 0;
    virtual int render_width() const = 0;
    virtual int render_height() const = 0;

    virtual void render(ICanvas *canvas, int16_t x, int16_t y) = 0;
    virtual ~IRenderable() = default;
};
#endif //MYSDL_IRENDERABLE_H
