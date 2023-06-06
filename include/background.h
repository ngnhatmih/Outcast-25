#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "sdl_game_object.h"
#include "layer.h"
#include "constant.h"
#include <unordered_map>


class Background
{
public:
    Background(): m_width(WIDTH), m_height(HEIGHT) {}

    virtual void draw();
    virtual void update();
    virtual void clean();
    virtual void loadLayer(std::string id, float scrollSpeed, bool scrollFlow) 
    { 
        m_layers[id] = new Layer(); 
        m_layers[id]->load(new LoaderParams(0, 0, m_width, m_height, 1, scrollSpeed, scrollFlow, id));
    }

protected:
    std::unordered_map<std::string, GameObject *> m_layers;
    float m_width;
    float m_height;
    SDL_BlendMode m_blendMode;

};

#endif /* BACKGROUND_H */