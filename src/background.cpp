#include "background.h"

void Background::draw()
{
    for (const auto &layer : m_layers)
    {
        layer.second->draw();
    }
}

void Background::update()
{
    int tmp_w;
    int tmp_h;
    SDL_GetWindowSize(Game::getInstance()->getWindow(), &tmp_w, &tmp_h);
    for (const auto &layer : m_layers)
    {
        layer.second->update();
    }
}

void Background::clean()
{
    for (const auto &layer : m_layers)
    {
        layer.second->clean();
    }

    m_layers.clear();
}
