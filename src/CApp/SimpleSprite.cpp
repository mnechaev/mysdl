//
// Created by Mikhail Nechaev on 14/09/17.
//

#include "SimpleSprite.h"
#include "SimpleSpriteRender.h"

SimpleSprite::SimpleSprite(): dx(1), dy(1) {}

const std::string SimpleSprite::cache_key() {
    return "SimpleSprite" + std::to_string(r);
}

IRenderable *SimpleSprite::render() {
    if (_render == nullptr) {
        _render = new SimpleSpriteRender(this);
    }
    return _render;
}

SimpleSprite::~SimpleSprite() {
    if (_render != nullptr)
        delete _render;
}
