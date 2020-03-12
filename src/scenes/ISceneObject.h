//
// Created by mnechaev on 12.03.2020.
//

#ifndef MYSDL_ISCENEOBJECT_H
#define MYSDL_ISCENEOBJECT_H

class ISceneObject {
public:
    virtual void on_added_to_scene() = 0;
    virtual void on_removed_from_scene() = 0;
    virtual ~ISceneObject() = default;
};

#endif //MYSDL_ISCENEOBJECT_H
