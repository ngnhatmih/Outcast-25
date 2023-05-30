#ifndef GAME_H
#define GAME_H

#include "texture_manager.h"

class Game
{
public:
    Game() {}
    ~Game() {}

    bool init(const char *title, int w, int h, Uint32 flags);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running() { return m_bRunning; }

private:
    bool m_bRunning;

    SDL_Window *m_pWindow;
    SDL_Renderer *m_pRenderer;

    TextureManager m_textureManager;
    int m_currentFrame;
};
#endif // GAME_H