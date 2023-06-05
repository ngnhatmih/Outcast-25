#include "button.h"

void Button::draw()
{
    SDLGameObject::draw();
}

void Button::update()
{
    if (checkCollision(InputHandler::getInstance()->getMousePos()))
    {
        m_currentFrame = BUTTON_OVER;
        if (InputHandler::getInstance()->getMouseButtonState(LEFT))
        {
            m_currentFrame = BUTTON_DOWN;
        }
    } 
    else { m_currentFrame = BUTTON_OUT; }
}

void Button::clean()
{
    SDLGameObject::clean();
}

void Button::load(LoaderParams *pLoader)
{
    SDLGameObject::load(pLoader);
}

bool Button::checkCollision(Vector2D pos)
{
    return SDLGameObject::checkCollision(pos);
}