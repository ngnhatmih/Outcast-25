#include "texture_manager.h"

TextureManager *TextureManager::instancePtr = 0;

bool TextureManager::load(std::string file, std::string id, SDL_Renderer *renderer)
{
    SDL_Texture *texture = 0;

    texture = IMG_LoadTexture(renderer, file.c_str());

    if(texture == 0)
    {
        std::cout << "Could not load the texture-ID: " << id << std::endl;
        return false;
    }
    else
    {
        std::cout << "Loaded successfully the texture-ID: " << id << std::endl;
        m_textures[id] = texture;
    }

    return true;
}

void TextureManager::draw(std::string id, float x, float y, float w, float h, float scale, SDL_Renderer *renderer, SDL_RendererFlip flip)
{
    SDL_FRect srcRect {0, 0, w, h};
    SDL_FRect desRect {x, y, w*scale, h*scale};

    SDL_RenderTextureRotated(renderer, m_textures[id], &srcRect, &desRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, float x, float y, float w, float h, float scale, int currentFrame, int currentRow, SDL_Renderer *renderer, SDL_RendererFlip flip)
{
    SDL_FRect srcRect {currentFrame*w, currentRow*h, w, h};
    SDL_FRect desRect {x, y, w*scale, h*scale};

    SDL_RenderTextureRotated(renderer, m_textures[id], &srcRect, &desRect, 0, 0, flip);
}