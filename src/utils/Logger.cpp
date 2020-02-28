//
// Created by mnechaev on 24.02.2020.
//

#include <iostream>
#include "Logger.h"

void Log::on_instance_create(const std::string &name) {
//    std::cout << "Create " << name << "..." << std::endl;
    _inst_created[name] += 1;
}

void Log::on_instance_destroy(const std::string &name) {
//    std::cout << "Destroy " << name << "..." << std::endl;
    _inst_destroyed[name] += 1;
}

void Log::info(const std::string &msg) {
    std::cout << msg << std::endl;
}

Log::Log() {
    std::cout << "create logger" << std::endl;
}

Log::~Log() {
    std::cout << "destroy logger" << std::endl;
}

void Log::result() {
    std::cout << "CREATED:" <<std::endl;
    for (auto ic : _inst_created) {
        std::cout << "\t" << ic.first << ":\t" << ic.second << std::endl;
    }
    std::cout << "DESTROYED:" <<std::endl;
    for (auto ic : _inst_destroyed) {
        std::cout << "\t" << ic.first << ":\t" << ic.second << std::endl;
    }
}

Log *Logger::_inst = nullptr;
