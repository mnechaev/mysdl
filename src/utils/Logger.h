//
// Created by mnechaev on 24.02.2020.
//

#ifndef MYSDL_LOGGER_H
#define MYSDL_LOGGER_H


#include <string>

class Logger {
public:
    void on_instance_create(const std::string &name);
    void on_instance_destroy(const std::string &name);
    void info(const std::string &msg);

    static Logger _inst;
    static Logger instance() {
        return _inst;
    }
};


#endif //MYSDL_LOGGER_H
