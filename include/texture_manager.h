#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <iostream>

#include <map>
#include <string>

#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>

class TextureManager
{
public:
    TextureManager(const TextureManager &) = delete;
    static TextureManager* getInstance()
    {
        if (instancePtr == nullptr)
        {
            instancePtr = new TextureManager();
        }
        return instancePtr;
    }

    bool load(std::string file, std::string id, SDL_Renderer *renderer);
    void draw(std::string id, float x, float y, float w, float h, float w_scale, float h_scale, SDL_Renderer *renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void drawFrame(std::string id, float x, float y, float w, float h, float scale, int currentFrame, int currentRow, SDL_Renderer *renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
    TextureManager() {}
    static TextureManager *instancePtr;
    std::map<std::string, SDL_Texture *> m_textures;
};

#endif /* TEXTURE_MANAGER_H */