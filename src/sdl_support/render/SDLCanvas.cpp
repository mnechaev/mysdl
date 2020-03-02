//
// Created by mnechaev on 28.02.2020.
//

#include <cmath>
#include "SDLCanvas.h"
#include "../../utils/Logger.h"

SDLCanvas::SDLCanvas(SDL_Surface *image, uint16_t width, uint16_t height):_image(image),
                                                                          _width(width),
                                                                          _height(height) {
    Logger::instance()->on_instance_create("SDLCanvas");
}

SDLCanvas::~SDLCanvas() {
    Logger::instance()->on_instance_destroy("SDLCanvas");
}

void SDLCanvas::drawRect(RRect &rect, uint32_t color) {
    SDL_Rect r{rect.x, rect.y, rect.w, rect.h};
    SDL_FillRect(_image, &r, color);
}

void SDLCanvas::setPixel(int16_t x, int16_t y, uint32_t color) {
    if (x < 0 || y < 0 || x > width() || y >= height()) return;

    uint32_t *pixmem32;
    pixmem32 = (Uint32*) _image->pixels + y * _image->pitch / 4 + x;
    *pixmem32 = color;
}

void SDLCanvas::drawCircle(RRect &rect, uint32_t color) {
    uint16_t r = rect.w / 2;
    uint16_t rr = r * r;
    for (int32_t x = -r; x < r; x++)
        for (int32_t y = -r; y < r; y++) {
            if (x*x + x + y*y + y - rr <= 0.5) setPixel(x + rect.x + r, y + rect.y + r, color);
        }
}

void SDLCanvas::drawCanvas(ICanvas *canvas_item, int16_t x, int16_t y) {
    drawSDLCanvas((SDLCanvas*) canvas_item, x, y);
}

void SDLCanvas::drawSDLCanvas(SDLCanvas *sdl_canvas_item, int16_t x, int16_t y) {
    SDL_Rect rect{x, y, sdl_canvas_item->width(), sdl_canvas_item->height()};
    SDL_BlitSurface(sdl_canvas_item->_image, NULL, _image, &rect);
}

uint16_t SDLCanvas::width() const {
    return _width;
}

uint16_t SDLCanvas::height() const {
    return _height;
}

SDL_Surface * SDLCanvas::image() const {
    return _image;
}

uint32_t SDLCanvas::color(uint8_t red, uint8_t green, uint8_t blue) {
    return SDL_MapRGB(_image->format, red, green, blue);
}

uint32_t SDLCanvas::bytes_size() const {
    return width() * height() * ceil(_image->format->BitsPerPixel / 8) + sizeof(SDLCanvas);
}

void SDLCanvas::clear(uint32_t color) {
    SDL_FillRect(_image, NULL, color);
}
