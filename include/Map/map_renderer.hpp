#include <iostream>
#include <Engine/game.hpp>
#include <SDL2/SDL_image.h>

#pragma once

class Map;

class MapRenderer{
    private:
        SDL_Surface *surface;
        SDL_Rect textureRect;

        Engine::Game *game;

        Map *map;

    public:
        MapRenderer(Engine::Game *game){this->game = game;};

        void init();

        void render();

        void createProvinceTextures(std::string colorMapPath);
};