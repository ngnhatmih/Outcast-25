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
    
    std::string m_TextureID;
    Vector2D m_pos;
    float m_width;
    float m_height;
    int m_numFrames;
    int m_currentRow;
    int m_currentFrame;
    float m_scale;
    float m_scrollSpeed;
    bool m_scrollFlow;
    float m_scrollOffSet = 0;
    
};

#endif /* LAYER_H */