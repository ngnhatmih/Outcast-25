#include "game.h"
#include "constant.h"

using namespace std;


int main(int argc, char *argv[])
{
    if(Game::getInstance()->init("outcast", WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE))
    {
        Uint32 frameStart, frameTime;

        while(Game::getInstance()->running())
        {
            frameStart = SDL_GetTicks();

            Game::getInstance()->handleEvents();
            Game::getInstance()->update();
            Game::getInstance()->render();

            frameTime = SDL_GetTicks() - frameStart;

            if (frameTime < DELAY_TIME)
            {
                SDL_Delay(DELAY_TIME - frameTime);
            }
        }
        Game::getInstance()->clean();
    }
    
    return EXIT_SUCCESS;
}