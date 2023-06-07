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
    Button(void (*callback)()): m_callback(callback) {}
    
    void draw();
    void update();
    void clean();
    void load(LoaderParams *pLoader);
    bool checkCollision(Vector2D pos);
    void setReleased(bool released) { m_released = released; }
    
protected:
    void (*m_callback) ();
    bool m_released = true;
    float m_xPercentages;
    float m_yPercentages;

};

#endif /* BUTTON_H */