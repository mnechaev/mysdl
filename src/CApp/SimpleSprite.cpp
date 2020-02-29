//
// Created by Mikhail Nechaev on 14/09/17.
//

#include "SimpleSprite.h"
#include "SimpleSpriteRender.h"
#include "../utils/Logger.h"

SimpleSprite::SimpleSprite(): dx(1), dy(1) {
    Logger::instance()->on_instance_create("SimpleSprite");
}

const std::string SimpleSprite::cache_key() {
    return "SimpleSprite" + std::to_string(r) + "#" + std::to_string(color_index);
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
    Logger::instance()->on_instance_destroy("SimpleSprite");
}
