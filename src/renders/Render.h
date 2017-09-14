#ifndef MYSDL_RENDER_H
#define MYSDL_RENDER_H


#include <cstdint>
#include "IRenderModel.h"

class Render {
public:
    explicit Render(IRenderModel *render_model);
    ~Render();

    bool init();
    void cleanup();

    bool beforeDraw();
    void afterDraw();

    uint32_t color(uint8_t r, uint8_t g, uint8_t b);

    void drawRect(RRect &rect, uint32_t color);
private:
    IRenderModel *_render_model;
};


#endif //MYSDL_RENDER_H
