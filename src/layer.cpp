#include "layer.h"
#include "game.h"
#include "constant.h"
#include "texture_manager.h"

void Layer::update()
{
    m_width = Game::getInstance()->getWindowSize().getX();
    m_height = Game::getInstance()->getWindowSize().getY();

    if (m_scrollOffSet > m_width)
    {
        m_scrollOffSet = 0;
    }
    if (m_scrollFlow)
    {
        m_scrollOffSet += m_scrollSpeed;
        
    }
    else { m_scrollOffSet -= m_scrollSpeed; }
}

void Layer::draw()
{
    TextureManager::getInstance()->draw(m_TextureID, m_scrollOffSet + ((m_scrollFlow) ? -1 : 1)*m_width, 0, m_width, m_height, 1, 1, Game::getInstance()->getRenderer());
    TextureManager::getInstance()->draw(m_TextureID, m_scrollOffSet, 0, m_width, m_height, 1, 1, Game::getInstance()->getRenderer());
}

void Layer::clean()
{
    SDLGameObject::clean();
}

void Layer::load(LoaderParams *pLoader)
{
    m_pos.setX(pLoader->getX());
    m_pos.setY(pLoader->getY());
    m_width = pLoader->getWidth();
    m_height = pLoader->getHeight();
    m_TextureID = pLoader->getTextureID();
    m_numFrames = pLoader->getNumFrames();
    m_scale = pLoader->getScale();
    m_scrollSpeed = pLoader->getScrollSpeed();
    m_scrollFlow = pLoader->getScrollFlow();
    m_currentFrame = 0;
    m_currentRow = 0;
}