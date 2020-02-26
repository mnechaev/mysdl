//
// Created by mnechaev on 26.02.2020.
//

#ifndef MYSDL_IRENDERABLE_H
#define MYSDL_IRENDERABLE_H

#include "../renders/Render.h"

class IRenderable {
public:
    void render(Render *renderer);
    virtual ~IRenderable() = default;
};
#endif //MYSDL_IRENDERABLE_H
