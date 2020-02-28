//
// Created by mnechaev on 28.02.2020.
//

#include "Cache.h"

Cache::Cache(ICanvasController *canvas_controller):_canvas_controller(canvas_controller) {
}

ICanvas *Cache::get_from_cache(const std::string &cache_key) {
    if (_cache_key == cache_key) return _cache;

    return nullptr;
}

void Cache::put_to_cache(const std::string &cache_key, ICanvas *canvas) {
    if (_cache != nullptr) {
        _canvas_controller->destroy_canvas(_cache);
    }

    _cache_key = cache_key;
    _cache = canvas;
}
