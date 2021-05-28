#include <iostream>
#include <SDL2/SDL.h>
#include <Engine/game.hpp>

#pragma once

namespace Engine{
    class Texture{
    public:
        Texture(Game *game);

        ~Texture();

        bool loadFromFile(std::string path, int size = 1);

        void free();

        //renders the texture with the given parameters
        //if w and h are set to -1, the texture will be rendered using the image's original size
        void render(int x, int y);

        int getWidth();
        int getHeight();

    private:
        SDL_Texture *texture = NULL;

        Game *game;

        int width, height;
    };
}