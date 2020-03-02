//
// Created by mnechaev on 28.02.2020.
//

#include "SimpleSpriteRender.h"
#include "../utils/Logger.h"

SimpleSpriteRender::SimpleSpriteRender(SimpleSprite *sprite):_sprite(sprite) {
    Logger::instance()->on_instance_create("SimpleSpriteRender");
}

SimpleSpriteRender::~SimpleSpriteRender() {
    Logger::instance()->on_instance_destroy("SimpleSpriteRender");
}

int SimpleSpriteRender::render_x() const {
    return _sprite->x / SS_COORD_SCALE;
}

int SimpleSpriteRender::render_y() const {
    return _sprite->y / SS_COORD_SCALE;
}

int SimpleSpriteRender::render_width() const {
    return _sprite->r * 2;
}

int SimpleSpriteRender::render_height() const {
    return _sprite->r * 2;
}

#define SELECT(val, A, B, C) (val) == 0 ? (A) : ((val) == 1 ? (B) : (C))

void SimpleSpriteRender::render(ICanvas *canvas, int16_t x, int16_t y) {
    RRect rect{};
    rect.x = x;
    rect.y = y;
    rect.w = _sprite->r * 2;
    rect.h = _sprite->r * 2;

    uint32_t color1 = canvas->color(255, 255, 255);
    uint32_t color2 = canvas->color(0, 0, 255);
    uint32_t color3 = canvas->color(255, 255, 0);

    canvas->drawRect(rect, SELECT(_sprite->color_index, color1, color2, color3));

    canvas->drawCircle(rect, SELECT(_sprite->color_index, color2, color3, color1));

    rect.w = (_sprite->r / 3) * 2;
    rect.h = rect.w;

    rect.x = x + _sprite->r + rect.w / 6;
    rect.y = y + _sprite->r - rect.h;
    canvas->drawCircle(rect, SELECT(_sprite->color_index, color3, color1, color2));

    rect.x = x + _sprite->r - rect.w - rect.w / 6;
    canvas->drawCircle(rect, SELECT(_sprite->color_index, color3, color1, color2));


    rect.w = (_sprite->r / 4) * 2;
    rect.h = rect.w;

    rect.x = x + _sprite->r - rect.w / 2;
    rect.y = _sprite->r + _sprite->r / 2 - rect.h / 2;
    canvas->drawCircle(rect, SELECT(_sprite->color_index, color3, color1, color2));
}
