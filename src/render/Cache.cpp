//
// Created by mnechaev on 28.02.2020.
//

#include "Cache.h"

Cache::Cache(ICanvasController *canvas_controller):_canvas_controller(canvas_controller) {
}

ICanvas *Cache::get_from_cache(const std::string &cache_key) {
    return map[cache_key];
}

void Cache::put_to_cache(const std::string &cache_key, ICanvas *canvas) {
    map[cache_key] = canvas;
}
