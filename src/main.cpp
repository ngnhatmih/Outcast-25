#include "game.h"

using namespace std;


int main(int argc, char *argv[])
{
    Game::getInstance()->init("outcast", 1000, 600, 0);

    while(Game::getInstance()->running())
    {
        Game::getInstance()->handleEvents();
        Game::getInstance()->update();
        Game::getInstance()->render();
    }

    Game::getInstance()->clean();
    
    return EXIT_SUCCESS;
}