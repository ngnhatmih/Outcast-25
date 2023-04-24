#include "Engine.h"

Engine::Engine()
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_version sdlVersion{};
    SDL_GetVersion(&sdlVersion);

    SDL_Log("This program is linked with SDL version %u.%u.%u", sdlVersion.major, sdlVersion.minor, sdlVersion.patch);

    SDL_Window* window = SDL_CreateWindow("Hello World", 800, 600, 0);

    if (window == NULL)
    {
        std::cout << "Could not create window" << SDL_GetError() << std::endl;
    }

    SDL_Event windowEvent;

    while (true)
    {
        if (SDL_PollEvent(&windowEvent))
        {
            if (windowEvent.type == SDL_EVENT_QUIT)
            {
                break;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}