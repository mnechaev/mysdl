#ifndef MYSDL_IRENDERMODEL_H
#define MYSDL_IRENDERMODEL_H


//typedef	short int16_t;
//typedef unsigned short uint16_t;
//typedef unsigned char uint8_t;
//typedef unsigned int uint32_t;

#include <cstdint>

typedef struct RRect {
    int16_t x, y;
    uint16_t w, h;
} RRect;

class IRenderModel {
public:
    virtual bool init() = 0;
    virtual void cleanup() = 0;

    virtual bool beforeDraw() = 0;
    virtual void afterDraw() = 0;

    virtual uint32_t color(uint8_t r, uint8_t g, uint8_t b) = 0;

    virtual void drawRect(RRect &rect, uint32_t color) = 0;

    int width();
    int height();
    virtual ~IRenderModel() = 0;
protected:
    IRenderModel(int width, int height);
private:
    int _width;
    int _height;
};


#endif //MYSDL_IRENDERMODEL_H
