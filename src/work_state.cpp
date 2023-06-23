#include "work_state.h"
#include "constant.h"
#include "game.h"

void WorkState::onEnter()
{
    SDL_Log("Entering work state...");
    SDL_SetRenderDrawBlendMode(Game::getInstance()->getRenderer(), SDL_BLENDMODE_NONE);
    m_commands["OpenFile"] = new OpenFileCommand();
    m_commands["OpenFolder"] = new OpenFolderCommand();

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
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem(ICON_CI_FILE " Open File", "Ctrl + O"))
            {
                m_commands["OpenFile"]->execute();
            }

            if (ImGui::MenuItem(ICON_CI_ROOT_FOLDER_OPENED " Open Folder", "Ctrl + shift + O"))
            {
                m_commands["OpenFolder"]->execute();
            }

            if (ImGui::MenuItem(ICON_CI_SAVE " Save File", "Ctrl + S"))
            {
            }
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Edit"))
        {
            if (ImGui::MenuItem(ICON_CI_EDIT " Cut"))
            {
            }

            if (ImGui::MenuItem(ICON_CI_COPY " Copy"))
            {
            }

            if (ImGui::MenuItem(ICON_CI_LAYERS " Paste"))
            {
            }
            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }

    float menuBarHeight = ImGui::GetFontSize() + ImGui::GetStyle().FramePadding.y * 2.0f;

    ImGui::SetNextWindowPos(ImVec2(0, menuBarHeight));
    //ImGui::SetNextWindowSizeConstraints(ImVec2(Game::getInstance()->getWindowSize().getX() * 0.2, Game::getInstance()->getWindowSize().getY()), ImVec2(Game::getInstance()->getWindowSize().getX(), Game::getInstance()->getWindowSize().getY()));
    ImGui::Begin("WorkTab");
    
    if (ImGui::BeginTabBar("WorkTab##TabBar", ImGuiTabBarFlags_TabListPopupButton | ImGuiTabBarFlags_Reorderable))
    {
        if (ImGui::BeginTabItem("Explorer")) 
        {
            FileExplorer::getInstance()->displayTree(FileExplorer::getInstance()->getFolderPath());
            ImGui::EndTabItem();
        }
        ImGui::EndTabBar();
    }

    ImGui::End();
    
    ImGui::SetNextWindowPos(ImVec2(Game::getInstance()->getWindowSize().getX() * 0.2, menuBarHeight));
    ImGui::Begin("Viewports");
    
    if (ImGui::BeginTabBar("Viewports##TabBar", ImGuiTabBarFlags_TabListPopupButton | ImGuiTabBarFlags_Reorderable))
    {
        if (ImGui::BeginTabItem("Explorer")) 
        {
            FileExplorer::getInstance()->displayTree(FileExplorer::getInstance()->getFolderPath());
            ImGui::EndTabItem();
        }
        ImGui::EndTabBar();
    }
    
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
    if (InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_LCTRL) || InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_RCTRL))
    {
        if (InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_O))
        {
            FileExplorer::getInstance()->openFile();
        }
    }
}

void WorkState::onKeyUp(SDL_Event event)
{
}

void WorkState::onWindowResize()
{
}