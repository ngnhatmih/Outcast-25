#include "game.h"
#include "UI.h"
#include "menu_state.h"
#include "work_state.h"

Game *Game::instancePtr = 0;
char a[5];

bool Game::init(const char *title, int w, int h, Uint32 flags)
{   
    SDL_Log("Initializing...");
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        m_pWindow = SDL_CreateWindow(title, w, h, flags);
        
        if (m_pWindow == 0)
        {
            SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s", SDL_GetError());
            return 0;
        } 
        else
        {
            SDL_Log("Window created successfully");

            m_pRenderer = SDL_CreateRenderer(m_pWindow, 0, SDL_RENDERER_ACCELERATED);
            if (m_pRenderer == 0)
            {
                SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create renderer: %s", SDL_GetError());
                return 0;
            }
            else 
            { 
                SDL_Log("Renderer created successfully");
                m_bRunning = 1;
            }
        }
    }
    else
    {
        std::cout << "Could not initialize SDL";
    }

    SDL_ShowWindow(m_pWindow);
    SDL_Log("Initialized SDL successfully");
    
    /* Imgui initializes */
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGui::StyleColorsDark();
    
    /* Imgui backend initializes */
    if (ImGui_ImplSDL3_InitForSDLRenderer(m_pWindow, m_pRenderer))
    {
        SDL_Log("Initialized imgui backend for SDL3 successfully");
        if (ImGui_ImplSDLRenderer3_Init(m_pRenderer))
        {
            SDL_Log("Initialized ImGui backend for SDL_Renderer successfully");
        }
        else
        {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not initialize ImGui backend for SDL_Renderer: %s", SDL_GetError());
            return 0;
        }
    }
    else
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not initialize ImGui backend for SDL3: %s", SDL_GetError());
        return 0;
    }

    GameStateMachine::getInstance()->pushState(new WorkState());

    return 1;
}

void Game::handleEvents()
{
    InputHandler::getInstance()->update();
}

void Game::update() 
{
    GameStateMachine::getInstance()->update();
}

void Game::render()
{
    ImGui_ImplSDLRenderer3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    
    ImGui::NewFrame();
    
    GameStateMachine::getInstance()->render();
}

void Game::clean()
{
    SDL_Log("Cleaning game...");

    /* Cleaning imgui... */
    ImGui_ImplSDLRenderer3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();

    /* Cleaning SDL... */
    SDL_DestroyRenderer(m_pRenderer);
    SDL_DestroyWindow(m_pWindow);
    SDL_Quit();
}

Vector2D Game::getWindowSize()
{
    int w_tmp;
    int h_tmp;
    SDL_GetWindowSize(m_pWindow, &w_tmp, &h_tmp);
    
    return Vector2D(w_tmp, h_tmp);
}
