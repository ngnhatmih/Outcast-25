#ifndef GAME_H
#define GAME_H

#include "texture_manager.h"
#include "player.h"

class Game
{
public:
    
    Game(const Game&) = delete;
    static Game *getInstance()
    {
        if (instancePtr == 0)
        {
            instancePtr = new Game();
        }
        return instancePtr;
    }
    
    bool init(const char *title, int w, int h, Uint32 flags);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running() { return m_bRunning; }

    SDL_Renderer *getRenderer() { return m_pRenderer; }

private:
    Game() {}
    static Game *instancePtr;
    bool m_bRunning;
    
    SDL_Window *m_pWindow;
    SDL_Renderer *m_pRenderer;
    
    int m_currentFrame;

    Player *p1;
};

#endif // GAME_H