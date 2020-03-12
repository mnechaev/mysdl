//
// Created by mnechaev on 12.03.2020.
//

#include <algorithm>
#include "Scene.h"


void Scene::add_object(ISceneObject *object) {
    objects.push_back(object);

    _tickable_objects.add_to_collection(object);
    _drawable_objects.add_to_collection(object);

    object->on_added_to_scene();
}

void Scene::remove_object(ISceneObject *object) {
    objects_vector::iterator pos = std::find(objects.begin(), objects.end(), object);
    if (pos == objects.end()) return;

    _tickable_objects.remove_from_collection(object);
    _drawable_objects.remove_from_collection(object);

    objects.erase(pos);
    object->on_removed_from_scene();
}

void Scene::on_added_to_scene() {

}

void Scene::on_removed_from_scene() {

}

void Scene::process_tick(uint32_t dt) {
    for (auto object : _tickable_objects) {
        object->process_tick(dt);
    }
}

void Scene::process_draw(ICanvas *canvas, int16_t x_offset, int16_t y_offset) {
    for (auto object : _drawable_objects) {
        object->process_draw(canvas, _x + x_offset, _x + y_offset);
    }
}
