//
// Created by mnechaev on 24.02.2020.
//

#include <iostream>
#include "Benchmark.h"

void Benchmark::init_on_frame(uint32_t time) {
    _frames_time = _frames_time_all = time;
    _frames = _frames_all = 0;
}

void Benchmark::on_frame(uint32_t time) {
    _frames++;
    _frames_all++;

    if (_frames < 1000) return;

    uint32_t now = time;

    uint32_t fps = (_frames * 1000 / (now - _frames_time));
    uint32_t fps_all = (_frames_all * 1000 / (now - _frames_time_all));
    std::cout << "FPS CURR: " << fps << "\tFPS AVR: " << fps_all << std::endl;

    _frames = 0;
    _frames_time = now;
}
