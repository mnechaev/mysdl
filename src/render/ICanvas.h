//
// Created by mnechaev on 28.02.2020.
//

#ifndef MYSDL_ICANVAS_H
#define MYSDL_ICANVAS_H

#include "renders.h"

class ICanvas {
public:
    virtual ~ICanvas() = default;

    virtual void drawRect(RRect &rect, uint32_t color) = 0;

    virtual void setPixel(int16_t x, int16_t y, uint32_t color) = 0;

    virtual void drawCircle(RRect &rect, uint32_t color) = 0;

    virtual void drawCanvas(ICanvas *canvas_item, int16_t x, int16_t y) = 0;

    virtual uint16_t width() const = 0;
    virtual uint16_t height() const = 0;
};

#endif //MYSDL_ICANVAS_H
