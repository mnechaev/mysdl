//
// Created by mnechaev on 28.02.2020.
//

#ifndef MYSDL_SDLCANVASCONTROLLER_H
#define MYSDL_SDLCANVASCONTROLLER_H

#include "../../render/ICanvasController.h"
#include "SDLCanvas.h"

#define BPP 32

class SDLCanvasController : public ICanvasController {
public:
    SDLCanvasController(uint16_t width, uint16_t height);
    ~SDLCanvasController();

    ICanvas *create_canvas(uint16_t width, uint16_t height) override;

    ICanvas *main_canvas() override;

    void destroy_canvas(ICanvas *canvas) override;
    void destroy_canvas(SDLCanvas *canvas);


    bool init() override;

    void cleanup() override;

    bool beforeDraw() override;

    void afterDraw() override;

    uint32_t color(uint8_t r, uint8_t g, uint8_t b) override;

private:
    uint16_t _width, _height;
    SDLCanvas *main;
};


#endif //MYSDL_SDLCANVASCONTROLLER_H
