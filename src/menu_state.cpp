#include "menu_state.h"
#include "play_state.h"
#include "button.h"
#include "game.h"
#include "constant.h"

void MenuState::onEnter()
{
    SDL_Log("Entering menu state...");

    /* Loading buttons */
    TextureManager::getInstance()->load("assets/PlayButton.png", "tButton::play", Game::getInstance()->getRenderer());

    m_gameObjects["oButton::play"] = new Button(play);
    m_gameObjects["oButton::play"]->load(new LoaderParams(0.5, 0.5, Game::getInstance()->getWindowSize().getX(), Game::getInstance()->getWindowSize().getY(), 100, 50, 1, "tButton::play", 3));
    
    /* Loading background's layers */
    TextureManager::getInstance()->load("assets/Clouds/1.png", "tCloud::Layer_1", Game::getInstance()->getRenderer());
    TextureManager::getInstance()->load("assets/Clouds/2.png", "tCloud::Layer_2", Game::getInstance()->getRenderer());
    TextureManager::getInstance()->load("assets/Clouds/3.png", "tCloud::Layer_3", Game::getInstance()->getRenderer());
    TextureManager::getInstance()->load("assets/Clouds/4.png", "tCloud::Layer_4", Game::getInstance()->getRenderer());

    m_background = new Background();
    m_background->loadLayer("tCloud::Layer_4", 1, 1);
    m_background->loadLayer("tCloud::Layer_3", 0.5, 1);
    m_background->loadLayer("tCloud::Layer_2", 0.25, 1);
    m_background->loadLayer("tCloud::Layer_1", 0, 1);

    SDL_SetRenderDrawBlendMode(Game::getInstance()->getRenderer(), SDL_BLENDMODE_NONE);

}

void MenuState::onExit()
{
    SDL_Log("Exiting menu state...");
    for (const auto &pair : m_gameObjects)
    {
        pair.second->clean();
    }

    m_gameObjects.clear();

    m_background->clean();
    delete m_background;
}

void MenuState::update()
{
    m_background->update();

    for (const auto &pair : m_gameObjects)
    {
        pair.second->update();
    }

}

void MenuState::render()
{

    ImGui::Render();

    SDL_RenderClear(Game::getInstance()->getRenderer());

    m_background->draw();

    for (const auto &pair : m_gameObjects)
    {
        pair.second->draw();
    }

    ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData());

    SDL_RenderPresent(Game::getInstance()->getRenderer());
}

void MenuState::onMouseMove(SDL_Event event)
{
    
}

void MenuState::onMouseButtonDown(SDL_Event event)
{

}

void MenuState::onMouseButtonUp(SDL_Event event)
{
    
}

void MenuState::onKeyDown(SDL_Event event)
{

}

void MenuState::onKeyUp(SDL_Event event)
{

}

void MenuState::onWindowResize()
{
    
}

GameObject *MenuState::getGameObject(std::string ID)
{
    return m_gameObjects[ID];
}

void MenuState::play()
{
    GameStateMachine::getInstance()->changeState(new PlayState());
}