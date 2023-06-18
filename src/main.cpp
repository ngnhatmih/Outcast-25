#include "game.h"     /* Contains everything of the game */
#include "constant.h" /* Game constants*/
#include <nfd.h>

int main(int argc, char *argv[])
{
    /* Initializes SDL and Dear Imgui */
    if (Game::getInstance()->init("outcast", WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE))
    {
        Uint32 frameStart, frameTime;

        /* Game loop */
        while (Game::getInstance()->running())
        {
            frameStart = SDL_GetTicks();

            Game::getInstance()->handleEvents();
            Game::getInstance()->update();
            Game::getInstance()->render();

            frameTime = SDL_GetTicks() - frameStart;

            if (frameTime < DELAY_TIME)
            {
                /* Delays offset the time when the frameTime drops below the delay time */
                SDL_Delay(DELAY_TIME - frameTime);
            }
        }
        /* End of game loop */
        Game::getInstance()->clean();
    }

    return EXIT_SUCCESS;
}