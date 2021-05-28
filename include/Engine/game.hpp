#include <iostream>
#include <SDL2/SDL.h>
#include <vector>

#pragma once

namespace Engine
{
    class Map;

    //abstract class for all game related functions
    class Game
    {
    private:
        //pointer to the game map
        Map *map;

    public:
        SDL_Renderer *renderer;
        SDL_Window *window;

        bool isRunning = false;

    public:
        void init();

        void handleEvents();

        void update();

        void render();
    };
}