#include "input_handler.h"

InputHandler *InputHandler::instancePtr = 0;

void InputHandler::onMouseMove(SDL_Event event)
{
    m_mousePos.setX(event.motion.x);
    m_mousePos.setY(event.motion.y);
    GameStateMachine::getInstace()->onMouseMove(event);
}

void InputHandler::onMouseButtonDown(SDL_Event event)
{
    switch(event.button.button)
    {
        case SDL_BUTTON_LEFT: m_mouseButtonStates[LEFT] = true; break;
        case SDL_BUTTON_MIDDLE: m_mouseButtonStates[MIDDLE] = true; break;
        case SDL_BUTTON_RIGHT: m_mouseButtonStates[RIGHT] = true; break;
    }
    GameStateMachine::getInstace()->onMouseButtonDown(event);
}

void InputHandler::onMouseButtonUp(SDL_Event event)
{
    switch(event.button.button)
    {
        case SDL_BUTTON_LEFT: m_mouseButtonStates[LEFT] = false; break;
        case SDL_BUTTON_MIDDLE: m_mouseButtonStates[MIDDLE] = false; break;
        case SDL_BUTTON_RIGHT: m_mouseButtonStates[RIGHT] = false; break;
    }
    GameStateMachine::getInstace()->onMouseButtonUp(event);
}

void InputHandler::reset()
{
    for (int i = 0; i < 3; ++i)
    {
        m_mouseButtonStates[i] = false;
    }
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
    if (m_keyStates != nullptr && m_keyStates[key])
    {
        return true;
    }
    else { return false; }
}

void InputHandler::onKeyDown(SDL_Event event)
{
    m_keyStates = SDL_GetKeyboardState(0);
    GameStateMachine::getInstace()->onKeyDown(event);
}

void InputHandler::onKeyUp(SDL_Event event)
{
    m_keyStates = SDL_GetKeyboardState(0);
    GameStateMachine::getInstace()->onKeyUp(event);
}

void InputHandler::update()
{
    SDL_Event event;
    ImGuiIO &io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    if (SDL_PollEvent(&event))
    {
        ImGui_ImplSDL3_ProcessEvent(&event);
        if (event.type == SDL_EVENT_QUIT)
        {
            GameStateMachine::getInstace()->onExit();
            Game::getInstance()->quit();
        }
        if (event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED && event.window.windowID == SDL_GetWindowID(Game::getInstance()->getWindow()))
        {
            GameStateMachine::getInstace()->onExit();
            Game::getInstance()->quit();
        }
        if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN)
        {
            onMouseButtonDown(event);
        }
        if (event.type == SDL_EVENT_MOUSE_BUTTON_UP)
        {
            onMouseButtonUp(event);
        }
        if (event.type == SDL_EVENT_MOUSE_MOTION)
        {
            onMouseMove(event);
        }
        if (event.type == SDL_EVENT_KEY_DOWN)
        {
            onKeyDown(event);
        }
        if (event.type == SDL_EVENT_KEY_DOWN)
        {
            onKeyUp(event);
        }
        if (event.type == SDL_EVENT_WINDOW_RESIZED)
        {
            int w_tmp;
            int h_tmp;
            SDL_GetWindowSize(Game::getInstance()->getWindow(), &w_tmp, &h_tmp);
            SDL_SetRenderLogicalPresentation(Game::getInstance()->getRenderer(), w_tmp, h_tmp, SDL_LOGICAL_PRESENTATION_STRETCH, SDL_SCALEMODE_BEST);
            GameStateMachine::getInstace()->onWindowResize();
        }
    }
}