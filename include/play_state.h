#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "game_state.h"

class PlayState: public GameState
{
public:
    PlayState() {}
    void update();
    void render();
    void onEnter();
    void onExit();
    void onMouseMove(SDL_Event event);
    void onMouseButtonDown(SDL_Event event);
    void onMouseButtonUp(SDL_Event event);
    void onKeyDown(SDL_Event event);
    void onKeyUp(SDL_Event event);
    void onWindowResize() {}
    std::string getStateID() { return m_stateID; }
    GameObject *getGameObject(std::string objectID);

protected:
    std::map<std::string, GameObject *> m_gameObjects;
    std::string m_stateID = "play";

};

#endif /* PLAY_STATE */