#ifndef LAYER_H
#define LAYER_H

#include <string>
#include "sdl_game_object.h"

class Layer: public SDLGameObject
{
public:
    Layer() {}
    void update();
    void draw();
    void clean();
    void load(LoaderParams *pLoader);

private:
    
    float m_scrollSpeed;
    bool m_scrollFlow;
    float m_scrollOffSet = 0;
    
};

#endif /* LAYER_H */