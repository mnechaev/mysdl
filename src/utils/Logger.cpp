//
// Created by mnechaev on 24.02.2020.
//

#include <iostream>
#include "Logger.h"

void Log::on_instance_create(const std::string &name) {
//    std::cout << "Create " << name << "..." << std::endl;
    _inst[name].created += 1;
}

void Log::on_instance_destroy(const std::string &name) {
//    std::cout << "Destroy " << name << "..." << std::endl;
    _inst[name].destroyed += 1;
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
    std::cout << "Classes operations:" << std::endl;
    for (auto item : _inst) {
        ClassOps &op = item.second;
        std::cout << "\t" << (op.valid() ? " " : ">") << " " << item.first
                  << " created: " << op.created
                  << ", destroyed: " << op.destroyed << std::endl;
    }
}

Log *Logger::_inst = nullptr;
