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

class Log {
public:
    Log();
    ~Log();
    void on_instance_create(const std::string &name);
    void on_instance_destroy(const std::string &name);
    void info(const std::string &msg);

    void result();

private:
    std::unordered_map<std::string, ClassOps> _inst;
};

class Logger {
public:
    static Log *_inst;
    static Log *instance() {
        if (_inst == nullptr) {
            _inst = new Log();
        }
        return _inst;
    }
};


#endif //MYSDL_LOGGER_H
