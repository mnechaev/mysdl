//
// Created by mnechaev on 28.02.2020.
//

#include "SimpleSpriteRender.h"
#include "../utils/Logger.h"

SimpleSpriteRender::SimpleSpriteRender(SimpleSprite *sprite):_sprite(sprite) {
    Logger::instance().on_instance_create("SimpleSpriteRender");
}

SimpleSpriteRender::~SimpleSpriteRender() {
    Logger::instance().on_instance_destroy("SimpleSpriteRender");
}

int SimpleSpriteRender::render_x() const {
    return _sprite->x;
}

int SimpleSpriteRender::render_y() const {
    return _sprite->y;
}

int SimpleSpriteRender::render_width() const {
    return _sprite->r * 2;
}

int SimpleSpriteRender::render_height() const {
    return _sprite->r * 2;
}

void SimpleSpriteRender::render(ICanvas *canvas, int16_t x, int16_t y) {
    RRect rect{};
    rect.x = x;
    rect.y = y;
    rect.w = _sprite->r * 2;
    rect.h = _sprite->r * 2;

    canvas->drawRect(rect, 255);

    canvas->drawCircle(rect, 255<<8);

    rect.x = x + _sprite->r;
    rect.y = y + _sprite->r;
    rect.w = (_sprite->r / 3) * 2;
    rect.h = rect.w;
    canvas->drawCircle(rect, 255 << 16);

}
