#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <SDL3/SDL.h>
#include "imgui.h"
#include <vector>
#include "vector2D.h"
#include "game.h"

enum mouse_button
{
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

class InputHandler
{
public:
    InputHandler(const InputHandler &) = delete;
    static InputHandler *getInstance()
    {
        if (instancePtr == nullptr)
        {
            instancePtr = new InputHandler();
        }
        return instancePtr;
    }

    /* Mouse inputs */
    Vector2D getMousePos() { return m_mousePos; }
    bool getMouseButtonState(enum mouse_button mouseState) { return m_mouseButtonStates[mouseState]; }

    void onMouseMove(SDL_Event event);
    void onMouseButtonDown(SDL_Event event);
    void onMouseButtonUp(SDL_Event event);

    void reset();

    /* Keyboard inputs */
    bool isKeyDown(SDL_Scancode key);
    void onKeyDown(SDL_Event event);
    void onKeyUp(SDL_Event event);
    
    void update();

private:
    InputHandler() 
    {
        for (int i = 0; i < 3; ++i)
        {
            m_mouseButtonStates.push_back(false);
        }
    }

    static InputHandler *instancePtr;
    std::vector<bool> m_mouseButtonStates;
    const Uint8 *m_keyStates;
    Vector2D m_mousePos;
};

#endif /* INPUT_HANDLER_H */
