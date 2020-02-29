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

    void clean();

    ICanvas *get_from_cache(const std::string &cache_key);
    ICanvas *create_cached(const std::string &cache_key, uint16_t width, uint16_t height);

private:
    ICanvasController *_canvas_controller;
    std::unordered_map<std::string, ICanvas*> map;
};


#endif //MYSDL_CACHE_H
