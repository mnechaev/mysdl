#include "Render.h"
#include "SDLRenderModel.h"
#include "../utils/Logger.h"

Render::Render(int width, int height) {
    Logger::instance().on_instance_create("Render");
    _render_model = new SDLRenderModel(width, height);
}

Render::~Render() {
    delete _render_model;
    _render_model = nullptr;

    Logger::instance().on_instance_destroy("Render");
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

int Render::width() {
    return this->_render_model->width();
}

int Render::height() {
    return this->_render_model->height();
}

uint32_t Render::color(uint8_t r, uint8_t g, uint8_t b) {
    return this->_render_model->color(r, g, b);
}

void Render::drawRect(RRect &rect, uint32_t color) {
    this->_render_model->drawRect(rect, color);
}

void Render::drawCircle(RRect &rect, uint32_t color) {
    this->_render_model->drawCircle(rect, color);
}
