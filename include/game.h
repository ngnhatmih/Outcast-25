#ifndef GAME_H
#define GAME_H

#include "texture_manager.h"
#include "input_handler.h"
#include "game_object.h"
#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"
#include "game_state_machine.h"

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
    void quit() { m_bRunning = 0; };
    bool running() { return m_bRunning; }

    SDL_Renderer *getRenderer() { return m_pRenderer; }
    SDL_Window *getWindow() { return m_pWindow; }

private:
    Game() {}
    static Game *instancePtr;
    bool m_bRunning;
    
    SDL_Window *m_pWindow;
    SDL_Renderer *m_pRenderer;
    
    int m_currentFrame;

};

#endif // GAME_H