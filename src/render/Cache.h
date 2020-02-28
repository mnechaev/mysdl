//
// Created by mnechaev on 28.02.2020.
//

#ifndef MYSDL_CACHE_H
#define MYSDL_CACHE_H

#include <string>
#include "ICanvas.h"
#include "ICanvasController.h"

class Cache {
public:
    Cache(ICanvasController *canvas_controller);

    ICanvas *get_from_cache(const std::string &cache_key);
    void put_to_cache(const std::string &cache_key, ICanvas *canvas);

private:
    ICanvasController *_canvas_controller;
    std::string _cache_key;
    ICanvas *_cache = nullptr;
};


#endif //MYSDL_CACHE_H
