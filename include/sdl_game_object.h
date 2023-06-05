#ifndef SDL_GAME_OBJECT_H
#define SDL_GAME_OBJECT_H

#include "game_object.h"
#include "vector2D.h"
#include "game.h"

class SDLGameObject: public GameObject
{
public:
    SDLGameObject() {}
    virtual void draw();
    virtual void update();
    virtual void clean();
    virtual void load(LoaderParams *pLoader);
    virtual bool checkCollision(Vector2D pos);

protected:
    Vector2D m_pos;
    Vector2D m_vec;
    Vector2D m_accel;
    
    float m_width;
    float m_height;
    std::string m_TextureID;
    int m_numFrames;
    int m_currentRow;
    int m_currentFrame;
    float m_scale;
};

#endif /* SDL_GAME_OBJECT_H */