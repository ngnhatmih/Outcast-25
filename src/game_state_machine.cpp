#include "game_state_machine.h"

GameStateMachine *GameStateMachine::instancePtr = 0;

void GameStateMachine::update()
{
    m_gameStates.top()->update();
}

void GameStateMachine::render()
{
    m_gameStates.top()->render();
}

void GameStateMachine::onEnter()
{
    m_gameStates.top()->onEnter();
}

void GameStateMachine::onExit()
{
    m_gameStates.top()->onExit();
}

void GameStateMachine::onMouseMove(SDL_Event event)
{
    m_gameStates.top()->onMouseMove(event);
}

void GameStateMachine::onMouseButtonDown(SDL_Event event)
{
    m_gameStates.top()->onMouseButtonDown(event);
}

void GameStateMachine::onMouseButtonUp(SDL_Event event)
{
    m_gameStates.top()->onMouseButtonUp(event);
}

void GameStateMachine::onKeyDown(SDL_Event event)
{
    m_gameStates.top()->onKeyDown(event);
}

void GameStateMachine::onKeyUp(SDL_Event event)
{
    m_gameStates.top()->onKeyUp(event);
}

void GameStateMachine::pushState(GameState *gameState)
{
    gameState->onEnter();
    m_gameStates.push(gameState);
}

void GameStateMachine::popState()
{
    m_gameStates.top()->onExit();
    m_gameStates.pop();
}

void GameStateMachine::changeState(GameState *gameState)
{
    if (!m_gameStates.empty() && getStateID() != gameState->getStateID())
    {
        popState();
        pushState(gameState);
    }
}