#include <Engine/texture.hpp>
#include <SDL2/SDL_image.h>

namespace Engine
{

    Texture::Texture(Game *game) { this->game = game; }

    void Texture::render(int x, int y)
    {
        if (texture == NULL)
            return;

        SDL_Rect renderQuad = {x, y, width, height};

        SDL_RenderCopy(game->renderer, texture, NULL, &renderQuad);
    }

    bool Texture::loadFromFile(std::string path, int size)
    {
        texture = IMG_LoadTexture(game->renderer, path.c_str());
        if (texture == NULL)
            return false;

        SDL_QueryTexture(texture, NULL, NULL, &width, &height);

        //multiply by size
        width *= size;
        height *= size;

        return true;
    }

    int Texture::getWidth() { return width; }
    int Texture::getHeight() { return height; }
}