#ifndef MYSDL_SDLRENDERMODEL_H
#define MYSDL_SDLRENDERMODEL_H

#include <SDL.h>
#include "IRenderModel.h"

class SDLRenderModel : public IRenderModel {
public:
    SDLRenderModel(int width, int height);
    ~SDLRenderModel() override;

    bool init() override;
    void cleanup() override;

    bool beforeDraw() override;
    void afterDraw() override;

    uint32_t color(uint8_t r, uint8_t g, uint8_t b) override;

    void drawRect(RRect &rect, uint32_t color) override;

private:
    SDL_Surface* surface;
};


#endif //MYSDL_SDLRENDERMODEL_H
