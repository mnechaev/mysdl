//
// Created by mnechaev on 28.02.2020.
//

#ifndef MYSDL_CACHE_H
#define MYSDL_CACHE_H

#include <string>
#include <unordered_map>
#include "ICanvas.h"
#include "ICanvasController.h"

class Cache {
public:
    Cache(ICanvasController *canvas_controller);
    ~Cache();

    ICanvas *get_from_cache(const std::string &cache_key);
    void put_to_cache(const std::string &cache_key, ICanvas *canvas);

private:
    ICanvasController *_canvas_controller;
    std::unordered_map<std::string, ICanvas*> map;
};


#endif //MYSDL_CACHE_H
