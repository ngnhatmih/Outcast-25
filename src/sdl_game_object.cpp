#include "sdl_game_object.h"

void SDLGameObject::load(LoaderParams *pLoader)
{
    m_pos.setX(pLoader->getX());
    m_pos.setY(pLoader->getY());
    m_width = pLoader->getWidth();
    m_height = pLoader->getHeight();
    m_TextureID = pLoader->getTextureID();
    m_numFrames = pLoader->getNumFrames();
    m_scale = pLoader->getScale();
    m_currentFrame = 0;
    m_currentRow = 0;
}

void SDLGameObject::draw()
{
    TextureManager::getInstance()->drawFrame(m_TextureID, m_pos.getX(), m_pos.getY(), m_width, m_height, m_scale, m_currentFrame, m_currentRow, Game::getInstance()->getRenderer());
}

void SDLGameObject::update()
{
    m_currentFrame = (SDL_GetTicks()/100)%m_numFrames;
}

void SDLGameObject::clean()
{
    delete this;
}

bool SDLGameObject::checkCollision(Vector2D pos)
{
    if (pos.getX() >= m_pos.getX() 
    &&  pos.getX() <= m_pos.getX() + m_width
    &&  pos.getY() >= m_pos.getY()
    &&  pos.getY() <= m_pos.getY() + m_height)
    { return true; }
    else {return false; }
}