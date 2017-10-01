//
// Created by Mikhail Nechaev on 14/09/17.
//

#include "SimpleSprite.h"

SimpleSprite::SimpleSprite():dx(1), dy(1) {}

void SimpleSprite::render(Render *renderer) {
    RRect rect{};
    rect.x = x;
    rect.y = y;
    rect.w = r * 2;
    rect.h = r * 2;

    renderer->drawRect(rect, renderer->color(255, 255, 255));

    renderer->drawCircle(rect, renderer->color(0, 0, 255));
}