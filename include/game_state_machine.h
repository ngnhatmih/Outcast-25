#ifndef GAME_STATE_MACHINE_H
#define GAME_STATE_MACHINE_H

#include "game_state.h"
#include <stack>

class GameStateMachine
{
public:
    GameStateMachine(const GameStateMachine &) = delete;
    static GameStateMachine *getInstace()
    {
        if (instancePtr == nullptr)
        {
            instancePtr = new GameStateMachine();
        }
        return instancePtr;
    }
    
    void update();
    void render();

    void onEnter();
    void onExit();

    void onMouseMove(SDL_Event event);
    void onMouseButtonDown(SDL_Event event);
    void onMouseButtonUp(SDL_Event event);

    void onKeyDown(SDL_Event event);
    void onKeyUp(SDL_Event event);

    void onWindowResize();
    
    std::string getStateID() { return m_gameStates.top()->getStateID(); }

    void pushState(GameState *gameState);
    void popState();
    void changeState(GameState *gameState);

private:
    GameStateMachine() {}
    static GameStateMachine *instancePtr;

    std::stack<GameState *> m_gameStates;
};

#endif /* GAME_STATE_MACHINE_H */