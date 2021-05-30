#include <Map/province.hpp>

void Province::changeColor(SDL_Surface *surface, int r,int g, int b)
{
    SDL_LockSurface(surface);
    Uint32 *temp = (Uint32 *)surface->pixels;
    for (int j = 0; j < pixels.size(); ++j)
    {
        int x = pixels[j]->x;
        int y = pixels[j]->y;
        temp[(x * surface->h) + y] = SDL_MapRGB(surface->format, r, g, b);
        // std::cout << "Test" << std::endl;
    }
    surface->pixels = temp;
    SDL_UnlockSurface(surface);
};