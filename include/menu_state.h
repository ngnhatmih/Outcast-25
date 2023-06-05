#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "game_state.h"
#include "background.h"
#include <stack>

class MenuState: public GameState 
{
public:
    MenuState() {}
    void update();
    void render();
    void onEnter();
    void onExit();
    void onMouseMove(SDL_Event event);
    void onMouseButtonDown(SDL_Event event);
    void onMouseButtonUp(SDL_Event event);
    void onKeyDown(SDL_Event event);
    void onKeyUp(SDL_Event event);
    std::string getStateID() { return m_stateID; }
    GameObject *getGameObject(std::string objectID);

private:
    std::map<std::string, GameObject *> m_gameObjects;
    std::string m_stateID = "menu";
    Background *m_background;
    
};

#endif /* MENU_STATE_H */