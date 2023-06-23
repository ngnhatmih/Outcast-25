#include "game.h"
#include "UI.h"
#include "menu_state.h"
#include "work_state.h"
#include "IconsCodicons.h"

Game *Game::instancePtr = 0;

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

    UI::getInstance()->setUpImGuiStyle();

    ImGuiIO io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard | ImGuiConfigFlags_DockingEnable;
    ImFont *defaultFont = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\cour.ttf", 16);
    io.Fonts->Build();

    io.FontDefault = defaultFont;

    float baseFontSize = 16.0f; 
    float iconFontSize = baseFontSize * 2.0f / 3.0f; 

    // Merge in icons from Codicons
    static const ImWchar icons_ranges[] = { ICON_MIN_CI, ICON_MAX_CI, 0 };
    ImFontConfig icons_config;
    icons_config.MergeMode = true;
    icons_config.PixelSnapH = true;
    icons_config.GlyphMinAdvanceX = iconFontSize;
    io.Fonts->AddFontFromFileTTF(FONT_ICON_FILE_NAME_CI, iconFontSize, &icons_config, icons_ranges);

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

    setupDockspace();
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

void Game::setupDockspace()
{
    int windowFlags = ImGuiWindowFlags_MenuBar;
    ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(getWindowSize().getX(), getWindowSize().getY()));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    windowFlags |= ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize 
                | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
    ImGui::Begin("Docking Space", new bool(true), windowFlags);
    ImGui::PopStyleVar(2);

}