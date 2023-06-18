#ifndef WORK_STATE_H
#define WORK_STATE_H

#include "game_state.h"

class WorkState: public GameState
{
public:
    WorkState() {}
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
    std::string getStateID() { return m_stateID; }
    GameObject *getGameObject(std::string objectID) { return m_gameObjects[objectID]; }
    void ShowOpenDialog();

private:
    std::map<std::string, GameObject *> m_gameObjects;
    std::string m_stateID = "work";
    std::string directory;

};
#endif /* WORK_STATE_H */