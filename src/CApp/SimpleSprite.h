//
// Created by Mikhail Nechaev on 14/09/17.
//

#ifndef MYSDL_SIMPLESPRITE_H
#define MYSDL_SIMPLESPRITE_H


#include "../render/IRenderable.h"
#include "../render/IRenderOwner.h"

class SimpleSprite : public IRenderOwner {
public:
    SimpleSprite();

    int x;
    int y;
    int r;
    int dx;
    int dy;

    const std::string cache_key() override;

    IRenderable *render() override;

private:
    IRenderable *_render = nullptr;
};


#endif //MYSDL_SIMPLESPRITE_H