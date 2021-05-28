// #include <iostream>
#include <Engine/game_object.hpp>
#include <Engine/game.hpp>
#include <Engine/texture.hpp>

using namespace Engine;

void GameObject::init(Game *game)
{
    this->game = game;

    texture = new Engine::Texture(game);
}

void GameObject::update()
{
    collider.x = x - originX;
    collider.y = y - originY;
}

void GameObject::render()
{
    // draw collider for debug
    // SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);
    // SDL_RenderFillRect(game->renderer, &collider);

    if (texture != NULL)
    {
        texture->render(x - originX, y - originY);
    }
}

void GameObject::handleEvents(SDL_Event *e) {}

void GameObject::setPosition(int x, int y){
    this->x = x;
    this->y = y;
}