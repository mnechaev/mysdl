//
// Created by mnechaev on 24.02.2020.
//

#include <iostream>
#include "Logger.h"

void Logger::on_instance_create(const std::string &name) {
//    std::cout << "Create " << name << "..." << std::endl;
    _insts_logs[name].created += 1;
}

void Logger::on_instance_destroy(const std::string &name) {
//    std::cout << "Destroy " << name << "..." << std::endl;
    _insts_logs[name].destroyed += 1;
}

void Logger::info(const std::string &msg) {
    std::cout << msg << std::endl;
}

void Logger::result() {
    std::cout << "Classes operations:" << std::endl;
    for (auto item : _insts_logs) {
        ClassOps &op = item.second;
        std::cout << "\t" << (op.valid() ? " " : ">") << " " << item.first
                  << " created: " << op.created
                  << ", destroyed: " << op.destroyed << std::endl;
    }
}

Logger *Logger::_inst = nullptr;
