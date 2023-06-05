#include "menu_state.h"
#include "button.h"
#include "game.h"
#include "constant.h"

void MenuState::onEnter()
{
    SDL_Log("Entering menu state...");
    m_gameObjects["oButton::play"] = new Button();
    m_gameObjects["oButton::play"]->load(new LoaderParams(CENTER_X-50, CENTER_Y-25, 100, 50, 1, "tButton::play", 3));

    /* Loading background's layers */
    TextureManager::getInstance()->load("assets/Clouds/1.png", "tCloud::Layer_1", Game::getInstance()->getRenderer());
    TextureManager::getInstance()->load("assets/Clouds/2.png", "tCloud::Layer_2", Game::getInstance()->getRenderer());
    TextureManager::getInstance()->load("assets/Clouds/3.png", "tCloud::Layer_3", Game::getInstance()->getRenderer());
    TextureManager::getInstance()->load("assets/Clouds/4.png", "tCloud::Layer_4", Game::getInstance()->getRenderer());

    m_background = new Background(576, 324);
    m_background->loadLayer("tCloud::Layer_4", 1, 1);
    m_background->loadLayer("tCloud::Layer_3", 0.5, 1);
    m_background->loadLayer("tCloud::Layer_2", 0.25, 1);
    m_background->loadLayer("tCloud::Layer_1", 0, 1);

    SDL_SetRenderDrawBlendMode(Game::getInstance()->getRenderer(), SDL_BLENDMODE_BLEND);

    
    
}

void MenuState::onExit()
{
    for (const auto &pair : m_gameObjects)
    {
        pair.second->clean();
    }

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

GameObject *MenuState::getGameObject(std::string ID)
{
    return m_gameObjects[ID];
}