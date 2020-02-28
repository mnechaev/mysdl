//
// Created by mnechaev on 28.02.2020.
//

#ifndef MYSDL_ICANVASCONTROLLER_H
#define MYSDL_ICANVASCONTROLLER_H

#include "ICanvas.h"

class ICanvasController {
public:
    virtual ~ICanvasController() = default;

    virtual ICanvas *create_canvas(uint16_t width, uint16_t height) = 0;
    virtual ICanvas *main_canvas() = 0;
    virtual void destroy_canvas(ICanvas *canvas) = 0;

    virtual bool init() = 0;
    virtual void cleanup() = 0;

    virtual bool beforeDraw() = 0;
    virtual void afterDraw() = 0;

    virtual uint32_t color(uint8_t r, uint8_t g, uint8_t b) = 0;
};

#endif //MYSDL_ICANVASCONTROLLER_H
