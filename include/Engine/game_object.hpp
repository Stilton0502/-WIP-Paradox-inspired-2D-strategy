#include <SDL2/SDL.h>
#include <Engine/texture.hpp>

#pragma once

namespace Engine
{
    class Game;
    class Texture;
    //class representing every gameobject, every gameobject class must inherit from this class
    class GameObject
    {
    protected:
        Game *game;

        int index;

        //position of the game object
        int x, y;

        //vellocity of the game object
        int dx, dy;
        
        int originX, originY;

        SDL_Rect collider;

        Texture *texture;

    public:
        virtual void init(Game *game);

        virtual void handleEvents(SDL_Event *e);

        virtual void update();

        virtual void render();

        void setPosition(int x, int y);

        void setIndex(int index) {this->index = index;};

        int getIndex() { return index; };

        SDL_Rect *getCollider() { return &collider; };

        Texture *getTexture() { return texture; };

        int getX() { return x; };

        int getY() { return y; };
    };
}