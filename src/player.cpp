#include "player.h"

void Player::load(LoaderParams *pLoader)
{
    SDLGameObject::load(pLoader);
}

void Player::draw()
{
    SDLGameObject::draw();
}

void Player::update()
{
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