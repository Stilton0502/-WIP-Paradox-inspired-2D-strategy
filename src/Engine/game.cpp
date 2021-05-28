#include <Engine/game.hpp>
#include <Engine/game_object.hpp>

using namespace Engine;

void Game::init()
{
    SDL_Init(SDL_INIT_VIDEO);

    this->window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);

    if (window != NULL)
    {
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        isRunning = true;
    }
}

void Game::handleEvents()
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        switch (e.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            for (int i = 0; i < gameObjects.size(); ++i)
            {
                if (gameObjects[i] == nullptr)
                    continue;

                gameObjects[i]->handleEvents(&e);
            }
            break;
        }
    }
}

void Game::update()
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        if (gameObjects[i] == nullptr)
            continue;
        gameObjects[i]->update();
    }
}

void Game::render()
{
    //Black background color
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    //Render all objects
    for (int i = 0; i < gameObjects.size(); i++)
    {
        if (gameObjects[i] == nullptr)
            continue;
        gameObjects[i]->render();
    }

    SDL_RenderPresent(renderer);
}

void Game::registerGameObject(GameObject *gameObject)
{
    this->gameObjects.push_back(gameObject);
    gameObject->setIndex(gameObjects.size() - 1);
    gameObject->init(this);
}

void Game::deRegisterGameObject(GameObject *gameObject)
{
    std::vector<GameObject*> temp;
    for(int i = 0; i < gameObjects.size(); ++i){
        if(gameObjects[i] == gameObject) continue;
        temp.push_back(gameObjects[i]);
    }
    gameObjects = temp;
    delete gameObject;
}

bool Game::isOverlapping(SDL_Rect *colliderA, SDL_Rect *colliderB, SDL_Rect *intersect)
{
    if (intersect == nullptr)
        intersect = new SDL_Rect();

    if (SDL_IntersectRect(colliderA, colliderB, intersect) == SDL_TRUE)
    {
        return true;
    }
    return false;
}

GameObject *Game::isOverlappingAny(SDL_Rect *colliderA, SDL_Rect *intersect)
{
    for (int i = 0; i < gameObjects.size(); ++i)
    {
        SDL_Rect *collider = gameObjects[i]->getCollider();

        if (collider == colliderA)
            continue;

        if (intersect == nullptr)
            intersect = new SDL_Rect();

        if (SDL_IntersectRect(colliderA, collider, intersect) == SDL_TRUE)
        {
            return gameObjects[i];
        }
    }
    return nullptr;
}

WindowSize Game::getWindowSize()
{
    int w, h;
    SDL_GetWindowSize(window, &w, &h);
    return WindowSize(w, h);
}