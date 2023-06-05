#ifndef BUTTON_H
#define BUTTON_H

#include "sdl_game_object.h"

enum button_state
{
    BUTTON_OUT = 0,
    BUTTON_OVER = 1,
    BUTTON_DOWN = 2
};

class Button: public SDLGameObject
{
public:
    Button() 
    {
        TextureManager::getInstance()->load("assets/PlayButton.png", "tButton::play", Game::getInstance()->getRenderer());
        m_released = true;
    }
    
    void draw();
    void update();
    void clean();
    void load(LoaderParams *pLoader);
    bool checkCollision(Vector2D pos);
    
protected:
    bool m_released;

};

#endif /* BUTTON_H */