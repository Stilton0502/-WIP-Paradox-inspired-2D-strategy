#include <iostream>
#include <SDL2/SDL.h>
#include <vector>

#pragma once

namespace Engine
{
    class GameObject;

    struct WindowSize
    {
        int w, h;
        WindowSize(int width, int height)
        {
            w = width;
            h = height;
        }
    };

    //abstract class for all game related functions
    class Game
    {
    protected:
        std::vector<GameObject *> gameObjects;

    public:
        SDL_Renderer *renderer;
        SDL_Window *window;

        bool isRunning = false;

    public:
        void init();

        void handleEvents();

        void update();

        void render();

        void registerGameObject(GameObject *gameObject);

        void deRegisterGameObject(GameObject *gameObject);

        //returns if colliderA and colliderB are overlapping and modifies intersect as the overlapping rect
        bool isOverlapping(SDL_Rect *colliderA, SDL_Rect *colliderB, SDL_Rect *intersect);

        //returns if colliderA is overlapping any gameobject in the scene. if true, it returns the overlapping collider
        GameObject *isOverlappingAny(SDL_Rect *colliderA, SDL_Rect *intersect);

        WindowSize getWindowSize();
    };
}