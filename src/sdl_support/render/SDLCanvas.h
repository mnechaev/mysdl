//
// Created by mnechaev on 28.02.2020.
//

#ifndef MYSDL_SDLCANVAS_H
#define MYSDL_SDLCANVAS_H


#include <SDL_video.h>
#include "../../render/renders.h"
#include "../../render/ICanvas.h"

class SDLCanvas : public ICanvas {
public:
    explicit SDLCanvas(SDL_Surface *image, uint16_t width, uint16_t height);
    ~SDLCanvas();

    void drawRect(RRect &rect, uint32_t color) override;

    void setPixel(int16_t x, int16_t y, uint32_t color) override;

    void drawCircle(RRect &rect, uint32_t color) override;

    void drawCanvas(ICanvas *canvas_item, int16_t x, int16_t y) override;
    void drawCanvas(SDLCanvas *canvas_item, int16_t x, int16_t y);

    uint16_t width() const override;

    uint16_t height() const override;

    SDL_Surface *image();

private:
    SDL_Surface *_image;
    uint16_t _width, _height;
};


#endif //MYSDL_SDLCANVAS_H
