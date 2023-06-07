#include "player.h"
#include "input_handler.h"

void Player::handleInput()
{
    if (InputHandler::getInstance()->getMouseButtonState(LEFT))
    {
        m_target = InputHandler::getInstance()->getMousePos();
    }

    m_vec = (m_target - m_pos)/50;

    if (m_pos != m_target)
    {
        m_pos += m_vec;
    } else { m_vec = Vector2D(0, 0); }
}

void Player::load(LoaderParams *pLoader)
{
    m_vec = Vector2D(0, 0);
    SDLGameObject::load(pLoader);
    m_target = m_pos;
}

void Player::draw()
{
    SDLGameObject::draw();
}

void Player::update()
{
    handleInput();
    SDLGameObject::update();
}

void Player::clean()
{
    SDLGameObject::clean();
}

bool Player::checkCollision(Vector2D pos)
{
    return SDLGameObject::checkCollision(pos);
}