//
// Created by mnechaev on 12.03.2020.
//

#ifndef MYSDL_SCENE_H
#define MYSDL_SCENE_H


#include <vector>
#include "SceneObjectsCollection.h"
#include "ISceneObject.h"
#include "ITickableObject.h"
#include "IDrawable.h"

class Scene : public ISceneObject, public ITickableObject, public IDrawable {
public:
    void add_object(ISceneObject* object);
    void remove_object(ISceneObject* object);

    void on_added_to_scene() override;

    void on_removed_from_scene() override;

    void process_tick(uint32_t dt) override;
    void process_draw(ICanvas *canvas, int16_t x_offset, int16_t y_offset) override;

private:
    int16_t _x = 0;
    int16_t _y = 0;

    typedef std::vector<ISceneObject*> objects_vector;
    objects_vector objects;

    SceneObjectsCollection<ITickableObject> _tickable_objects;
    SceneObjectsCollection<IDrawable> _drawable_objects;
};


#endif //MYSDL_SCENE_H
