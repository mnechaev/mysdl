#include "IRenderModel.h"

IRenderModel::IRenderModel(int width, int height):
        _width(width),_height(height) {}
IRenderModel::~IRenderModel() = default;

int IRenderModel::width() {
    return _width;
}

int IRenderModel::height() {
    return _height;
}