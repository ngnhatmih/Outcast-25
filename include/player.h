#ifndef PLAYER_H
#define PLAYER_H

#include "sdl_game_object.h"

class Player: public SDLGameObject
{
public:
    Player() {}
    virtual void draw();
    virtual void update();
    virtual void clean();
    virtual void load(LoaderParams *pLoader);
    virtual bool checkCollision(Vector2D pos);

};

#endif /* PLAYER_H */