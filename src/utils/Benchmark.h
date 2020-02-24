//
// Created by mnechaev on 24.02.2020.
//

#ifndef MYSDL_BENCHMARK_H
#define MYSDL_BENCHMARK_H


#include <cstdint>

class Benchmark {
public:
    void init_on_frame(uint32_t time);
    void on_frame(uint32_t time);

private:
    uint32_t _frames_time;
    uint32_t _frames_time_all;
    uint32_t _frames;
    uint32_t _frames_all;
};


#endif //MYSDL_BENCHMARK_H
