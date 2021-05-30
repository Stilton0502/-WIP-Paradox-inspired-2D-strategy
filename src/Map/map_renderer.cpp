#include <Map/map_renderer.hpp>
#include <Map/map.hpp>
#include <map>

void MapRenderer::init(){
    //parse the map_data to render
    createProvinceTextures("map/provinces.bmp");
}

void MapRenderer::render(){
    SDL_Texture *texture = SDL_CreateTextureFromSurface(game->renderer, surface);
    if (texture != nullptr)
        SDL_RenderCopy(game->renderer, texture, NULL, &textureRect);
}

void MapRenderer::createProvinceTextures(std::string colorMapPath)
{
    surface = IMG_Load(colorMapPath.c_str());

    if (surface == NULL)
    {
        perror("Couldn't load color map");
        return;
    }

    int w = surface->w;
    int h = surface->h;

    textureRect.w = w / 4;
    textureRect.h = h / 4;

    SDL_LockSurface(surface);
    //get all pixels of the color map
    Uint32 *pixels = (Uint32 *)surface->pixels;

    //map colors to provinces
    std::map<std::string, Province *> colorToProvince;
    for (int i = 0; i < map->getProvincesLength(); ++i)
    {
        Province *province = map->getProvinces()[i];
        std::string colorName = std::to_string(province->r) + "," + std::to_string(province->g) + "," + std::to_string(province->b);
        if (colorToProvince.find(colorName) == colorToProvince.end())
        {
            colorToProvince.insert(std::pair<std::string, Province *>(colorName, province));
        }
    }

    //iterate through every pixel and find the mapped province for the pixel's color to assign the pixel positions to the provinces
    for (int x = 0; x < w; ++x)
    {
        for (int y = 0; y < h; ++y)
        {
            Uint32 pixel = pixels[(x * h) + y];
            Uint8 r, g, b;
            SDL_GetRGB(pixel, surface->format, &r, &g, &b);

            std::string colorName = std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b);
            if (colorToProvince.find(colorName) != colorToProvince.end())
            {
                Province *province = colorToProvince[colorName];
                if (province != nullptr)
                {
                    province->pixels.push_back(new Vector2(x,y));
                }
            }
        }
    }

    SDL_UnlockSurface(surface);
}