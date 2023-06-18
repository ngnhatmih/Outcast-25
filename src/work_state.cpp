#include "work_state.h"
#include "constant.h"
#include "file_dialogs.h"
#include "game.h"


void WorkState::onEnter()
{
    SDL_Log("Entering work state...");
    SDL_SetRenderDrawBlendMode(Game::getInstance()->getRenderer(), SDL_BLENDMODE_NONE);
}

void WorkState::onExit()
{
    SDL_Log("Exiting work state...");
    for (const auto &pair : m_gameObjects)
    {
        pair.second->clean();
    }

    m_gameObjects.clear();
}

void WorkState::update()
{
    for (const auto &pair : m_gameObjects)
    {
        pair.second->update();
    }
}

void WorkState::render()
{
    if (ImGui::BeginMainMenuBar())
    {
        ImGui::SetCursorPosX(0);
        if (ImGui::BeginMenu("File")) {
            if (ImGui::MenuItem("Open", "Ctrl + O")) {
                FileDialogs::getInstance()->openFile();
            }

            if (ImGui::MenuItem("Save")) {
                    
            }
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Edit")) {
            if (ImGui::MenuItem("Cut")) {
                
            }

            if (ImGui::MenuItem("Copy")) {
               
            }
            
            if (ImGui::MenuItem("Paste")) {
                   
            }
            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();

    }
    
    float menuBarHeight = ImGui::GetFontSize() + ImGui::GetStyle().FramePadding.y * 2.0f;

    ImGui::SetNextWindowPos(ImVec2(0, menuBarHeight));
    ImGui::SetNextWindowSizeConstraints(ImVec2(Game::getInstance()->getWindowSize().getX() * 0.2, Game::getInstance()->getWindowSize().getY()), ImVec2(Game::getInstance()->getWindowSize().getX(), Game::getInstance()->getWindowSize().getY()));
    ImGui::Begin("Explorer", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoTitleBar);

    ImGui::Text("</> Explorer");

    ImGui::End();

    ImGui::Render();

    SDL_RenderClear(Game::getInstance()->getRenderer());

    for (const auto &pair : m_gameObjects)
    {
        pair.second->draw();
    }

    ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData());

    SDL_RenderPresent(Game::getInstance()->getRenderer());
}

void WorkState::onMouseMove(SDL_Event event)
{
}

void WorkState::onMouseButtonDown(SDL_Event event)
{
}

void WorkState::onMouseButtonUp(SDL_Event event)
{
}

void WorkState::onKeyDown(SDL_Event event)
{
}

void WorkState::onKeyUp(SDL_Event event)
{
}

void WorkState::onWindowResize()
{
}
