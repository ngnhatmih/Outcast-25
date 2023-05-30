#include "player.h"
#include "game.h"

void Player::load(LoaderParams *pLoader)
{
    m_x = pLoader->getX();
    m_y = pLoader->getY();
    m_width = pLoader->getWidth();
    m_height = pLoader->getHeight();
    m_TextureID = pLoader->getTextureID();
    m_numFrames = pLoader->getNumFrames();
    m_currentFrame = 0;
    m_currentRow = 0;
}

void Player::draw()
{
    TextureManager::getInstance()->drawFrame(m_TextureID, m_x, m_y, m_width, m_height, 3, m_currentFrame, m_currentRow, Game::getInstance()->getRenderer());
}

void Player::update()
{
    m_currentFrame = (SDL_GetTicks()/100)%m_numFrames;
}

void Player::clean()
{

}