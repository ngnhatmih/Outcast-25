#include "button.h"

void Button::draw()
{
    SDLGameObject::draw();
}

void Button::update()
{
    float x = Game::getInstance()->getWindowSize().getX()*m_xPercentages - m_width/2;
    float y = Game::getInstance()->getWindowSize().getY()*m_yPercentages- m_height/2;
    
    if (x != m_pos.getX() || y != m_pos.getY())
    {
        m_pos.setX(x);
        m_pos.setY(y);
    }

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
    m_pos = Vector2D(pLoader->getX(), pLoader->getY());
    m_xPercentages = pLoader->getXPercentages();
    m_yPercentages = pLoader->getYPercentages();
    m_width = pLoader->getWidth();
    m_height = pLoader->getHeight();
    m_TextureID = pLoader->getTextureID();
    m_numFrames = pLoader->getNumFrames();
    m_scale = pLoader->getScale();
    m_currentFrame = 0;
    m_currentRow = 0;

}

bool Button::checkCollision(Vector2D pos)
{
    return SDLGameObject::checkCollision(pos);
}