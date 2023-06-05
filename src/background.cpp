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
}
