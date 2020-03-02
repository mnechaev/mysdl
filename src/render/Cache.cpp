//
// Created by mnechaev on 28.02.2020.
//

#include "Cache.h"
#include "../utils/Logger.h"

Cache::Cache(ICanvasController *canvas_controller):_canvas_controller(canvas_controller) {
    Logger::instance()->on_instance_create("Cache");
}

ICanvas *Cache::get_from_cache(const std::string &cache_key) {
    return map[cache_key];
}

ICanvas *Cache::create_cached(const std::string &cache_key, uint16_t width, uint16_t height) {
    ICanvas *cached = _canvas_controller->create_canvas(width, height);
    map[cache_key] = cached;
    _cache_bytes_size += cached->bytes_size();
    Logger::instance()->info("Cache size: " + std::to_string(_cache_bytes_size));

    return cached;
}

void Cache::clean() {
    for (auto item : map) {
        _canvas_controller->destroy_canvas(item.second);
    }
    _cache_bytes_size = 0;
    map.clear();
}

Cache::~Cache() {
    clean();
    Logger::instance()->on_instance_destroy("Cache");
}
