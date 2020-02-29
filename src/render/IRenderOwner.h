//
// Created by mnechaev on 28.02.2020.
//

#ifndef MYSDL_IRENDEROWNER_H
#define MYSDL_IRENDEROWNER_H

#include <string>
#include "IRenderable.h"

class IRenderOwner {
public:
    virtual const std::string & cache_key() = 0;
    virtual IRenderable *render() = 0;

    virtual ~IRenderOwner() = default;
};

#endif //MYSDL_IRENDEROWNER_H
