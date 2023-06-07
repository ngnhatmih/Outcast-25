#include "play_state.h"
#include "button.h"
#include "player.h"
#include "game.h"
#include "constant.h"

void PlayState::onEnter()
{
    SDL_Log("Entering play state...");

    SDL_SetWindowSize(Game::getInstance()->getWindow(), 800, 600);

    m_gameObjects["oPlayer"] = new Player();
    TextureManager::getInstance()->load("assets/Player/idle.png", "tPlayer::idle", Game::getInstance()->getRenderer());

    m_gameObjects["oPlayer"]->load(new LoaderParams(400, 300, 128, 128, 0.25, "tPlayer::idle", 30));

    SDL_SetRenderDrawBlendMode(Game::getInstance()->getRenderer(), SDL_BLENDMODE_NONE);
    SDL_SetRenderDrawColor(Game::getInstance()->getRenderer(), 255, 255, 255, 255);

}

void PlayState::onExit()
{
    SDL_Log("Exiting play state...");
    for (const auto &pair : m_gameObjects)
    {
        pair.second->clean();
    }

    m_gameObjects.clear();

}

void PlayState::update()
{

    for (const auto &pair : m_gameObjects)
    {
        pair.second->update();
    }

}

void PlayState::render()
{

    ImGui::Render();

    SDL_RenderClear(Game::getInstance()->getRenderer());

    for (const auto &pair : m_gameObjects)
    {
        pair.second->draw();
    }

    ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData());

    SDL_RenderPresent(Game::getInstance()->getRenderer());
}

void PlayState::onMouseMove(SDL_Event event)
{
    
}

void PlayState::onMouseButtonDown(SDL_Event event)
{

}

void PlayState::onMouseButtonUp(SDL_Event event)
{

}

void PlayState::onKeyDown(SDL_Event event)
{

}

void PlayState::onKeyUp(SDL_Event event)
{

}

GameObject *PlayState::getGameObject(std::string ID)
{
    return m_gameObjects[ID];
}
