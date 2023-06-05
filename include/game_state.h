#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <iostream>
#include <string>
#include "game_object.h"

class GameState
{
public:
    virtual void update() = 0;
    virtual void render() = 0;
    virtual void onEnter() = 0;
    virtual void onExit() = 0;
    virtual void onMouseMove(SDL_Event event) = 0;
    virtual void onMouseButtonDown(SDL_Event event) = 0;
    virtual void onMouseButtonUp(SDL_Event event) = 0;
    virtual void onKeyDown(SDL_Event event) = 0;
    virtual void onKeyUp(SDL_Event event) = 0;
    virtual std::string getStateID() = 0;
    virtual GameObject *getGameObject(std::string objectID) = 0;

protected:
    GameState() {}
    virtual ~GameState() {}

};

#endif /* GAME_STATE_H */