//
// Created by Mikhail Nechaev on 14/09/17.
//

#ifndef MYSDL_SIMPLESPRITE_H
#define MYSDL_SIMPLESPRITE_H


#include "../renders/Render.h"

class SimpleSprite {
public:
    SimpleSprite();

    int x;
    int y;
    int r;
    int dx;
    int dy;

    void render(Render* renderer);
};


#endif //MYSDL_SIMPLESPRITE_H