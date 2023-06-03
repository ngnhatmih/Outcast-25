#include "game.h"

Game *Game::instancePtr = 0;

bool Game::init(const char *title, int w, int h, Uint32 flags)
{   
    std::cout << "Initializing..." << std::endl;
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        m_pWindow = SDL_CreateWindow(title, w, h, 0);
        
        if (m_pWindow == 0)
        {
            std::cout << "Could not create window: " << SDL_GetError() << std::endl;
            return 0;
        } 
        else
        {
            std::cout << "Window created successfully" << std::endl;

            m_pRenderer = SDL_CreateRenderer(m_pWindow, 0, SDL_RENDERER_ACCELERATED);
            if (m_pRenderer == 0)
            {
                std::cout << "Could not create renderer: " << SDL_GetError() << std::endl;
                return 0;
            }
            else 
            { 
                std::cout << "Renderer created successfully" << std::endl;
                m_bRunning = 1;
            }
        }
    }
    else
    {
        std::cout << "Could not initialize SDL";
    }

    std::cout << "Initialized SDL successfully" << std::endl;
    
    /* Loads assets */
    TextureManager::getInstance()->load("assets/download.bmp", "download", m_pRenderer);
    TextureManager::getInstance()->load("assets/Vampire/BatVampire_Flying.png", "player", m_pRenderer);
    
    /* Initializes player */
    p1 = new Player();
    p1->load(new LoaderParams(200, 200, 32, 32, "player", 4));

    SDL_SetRenderDrawColor(m_pRenderer, 255, 192, 203, 255);

    return 1;
}

void Game::handleEvents()
{
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        if(event.type == SDL_EVENT_QUIT)
        {
            m_bRunning = 0;
        }
    }
}

void Game::update() 
{
    p1->update();
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);
    p1->draw();
    SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
    std::cout <<"Cleaning game...";
    SDL_DestroyRenderer(m_pRenderer);
    SDL_DestroyWindow(m_pWindow);
    SDL_Quit();
}
