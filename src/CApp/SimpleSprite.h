//
// Created by Mikhail Nechaev on 14/09/17.
//

#ifndef MYSDL_SIMPLESPRITE_H
#define MYSDL_SIMPLESPRITE_H


#include <memory>
#include "../render/IRenderable.h"
#include "../render/IRenderOwner.h"

#define SS_COORD_SCALE 1000
#define SS_REAL_SPEED 200

class SimpleSprite : public IRenderOwner {
public:
    typedef std::shared_ptr<SimpleSprite> pointer;
    static pointer create();
    SimpleSprite();
    ~SimpleSprite();

    int x;
    int y;
    int r;
    int dx;
    int dy;
    int color_index = 0;

    const std::string & cache_key() override;
    void invalidate_cache();

    IRenderable *render() override;

private:
    std::string *_cache_key = nullptr;
    IRenderable *_render = nullptr;
};


#endif //MYSDL_SIMPLESPRITE_H