//
// Created by mnechaev on 24.02.2020.
//

#include <iostream>
#include "Logger.h"

void Logger::on_instance_create(const std::string &name) {
    std::cout << "Create " << name << "..." << std::endl;
}

void Logger::on_instance_destroy(const std::string &name) {
    std::cout << "Destroy " << name << "..." << std::endl;
}

void Logger::info(const std::string &msg) {
    std::cout << msg << std::endl;
}
