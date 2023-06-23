#ifndef SCENE_H
#define SCENE_H

#include "game_object.h"
#include "environment.h"

#include <string>
#include <map>

class Scene
{
public:
    Scene(std::string filename) {}
    Scene() {}

private:
    std::map<std::string, GameObject *> m_gameObjects;
    Environment m_env;
    
};

#endif /* SCENE_H */