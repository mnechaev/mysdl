//
// Created by mnechaev on 12.03.2020.
//

#ifndef MYSDL_SCENEOBJECTSCOLLECTION_H
#define MYSDL_SCENEOBJECTSCOLLECTION_H


#include <vector>
#include "ISceneObject.h"

template <typename T>
class SceneObjectsCollection : public std::vector<T*> {
public:
    void add_to_collection(ISceneObject* object);
    void remove_from_collection(ISceneObject* object);
};

template<typename T>
void SceneObjectsCollection<T>::add_to_collection(ISceneObject *object) {
    T *target = dynamic_cast<T*>(object);
    if (target == nullptr) return;

    this->push_back(target);
}

template<typename T>
void SceneObjectsCollection<T>::remove_from_collection(ISceneObject *object) {
    T *target = dynamic_cast<T*>(object);
    if (target == nullptr) return;

    auto pos = std::find(this->begin(), this->end(), target);
    if (pos == this->end()) return;
    this->erase(pos);
}


#endif //MYSDL_SCENEOBJECTSCOLLECTION_H
