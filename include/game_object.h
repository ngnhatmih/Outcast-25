#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "loader_params.h"

/* This is abstract class */ 
class GameObject
{
public:
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;
    virtual void load(LoaderParams *pLoader) = 0;

protected:
    GameObject() {}
    virtual ~GameObject() {}
};

#endif /* GAME_OBJECT_H */