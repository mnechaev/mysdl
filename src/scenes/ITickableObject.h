//
// Created by mnechaev on 12.03.2020.
//

#ifndef MYSDL_ITICKABLEOBJECT_H
#define MYSDL_ITICKABLEOBJECT_H

#include <cstdint>

class ITickableObject {
public:
    virtual void process_tick(uint32_t dt) = 0;
    virtual ~ITickableObject() = default;
};

#endif //MYSDL_ITICKABLEOBJECT_H
