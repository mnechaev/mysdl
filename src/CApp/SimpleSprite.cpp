//
// Created by Mikhail Nechaev on 14/09/17.
//

#include <iostream>
#include "SimpleSprite.h"
#include "SimpleSpriteRender.h"
#include "../utils/Logger.h"

SimpleSprite::SimpleSprite(): dx(1), dy(1) {
    Logger::instance()->on_instance_create("SimpleSprite");
}

const std::string & SimpleSprite::cache_key() {
    if (_cache_key == nullptr) {
        _cache_key = new std::string("SimpleSprite" + std::to_string(r) + "#" + std::to_string(color_index));
    }
    return *_cache_key;
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

    if (_cache_key != nullptr)
        delete _cache_key;

    Logger::instance()->on_instance_destroy("SimpleSprite");
}

void SimpleSprite::invalidate_cache() {
    if (_cache_key == nullptr) return;

    delete _cache_key;
    _cache_key = nullptr;
}
