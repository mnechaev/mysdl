//
// Created by mnechaev on 28.02.2020.
//

#ifndef MYSDL_SIMPLESPRITERENDER_H
#define MYSDL_SIMPLESPRITERENDER_H


#include "../render/IRenderable.h"
#include "SimpleSprite.h"

class SimpleSpriteRender : public IRenderable {
public:
    SimpleSpriteRender(SimpleSprite *sprite);

    int render_x() const override;
    int render_y() const override;
    int render_width() const override;
    int render_height() const override;

    void render(ICanvas *canvas, int16_t x, int16_t y) override;

    ~SimpleSpriteRender() override;

private:
    SimpleSprite *_sprite;
};


#endif //MYSDL_SIMPLESPRITERENDER_H
