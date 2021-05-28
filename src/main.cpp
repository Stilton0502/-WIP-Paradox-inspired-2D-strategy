#include <iostream>
#include <Engine/game.hpp>

int main()
{
    Engine::Game *game = new Engine::Game();
    game->init();

    while (game->isRunning)
    {
        game->handleEvents();
        game->update();
        game->render();
    }

    return 0;
}
