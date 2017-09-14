#include "Render.h"
#include <iostream>
Render::Render(IRenderModel *render_model) : _render_model(render_model) {
    std::cout << "Create Render..." << std::endl;
}

Render::~Render() {
    delete _render_model;
    std::cout << "Destroy Render..." << std::endl;
}

bool Render::init() {
    return this->_render_model->init();
}

void Render::cleanup() {
    return this->_render_model->cleanup();
}

bool Render::beforeDraw() {
    return this->_render_model->beforeDraw();
}

void Render::afterDraw() {
    this->_render_model->afterDraw();
}

uint32_t Render::color(uint8_t r, uint8_t g, uint8_t b) {
    return this->_render_model->color(r, g, b);
}

void Render::drawRect(RRect &rect, uint32_t color) {
    this->_render_model->drawRect(rect, color);
}
