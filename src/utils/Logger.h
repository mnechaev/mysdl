//
// Created by mnechaev on 24.02.2020.
//

#ifndef MYSDL_LOGGER_H
#define MYSDL_LOGGER_H


#include <string>
#include <unordered_map>

struct ClassOps {
    uint16_t created, destroyed;
    bool valid() {
        return created == destroyed;
    }
};

class Logger {
public:
    static Logger *_inst;
    static Logger *instance() {
        if (_inst == nullptr) {
            _inst = new Logger();
        }
        return _inst;
    }

    void on_instance_create(const std::string &name);
    void on_instance_destroy(const std::string &name);
    void info(const std::string &msg);

    void result();

private:
    Logger() {}
    Logger(Logger const &);
    Logger& operator=(Logger const &);

    std::unordered_map<std::string, ClassOps> _insts_logs;
};


#endif //MYSDL_LOGGER_H
