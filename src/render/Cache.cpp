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

void Cache::put_to_cache(const std::string &cache_key, ICanvas *canvas) {
    map[cache_key] = canvas;
}

Cache::~Cache() {
    Logger::instance()->on_instance_destroy("Cache");
}
