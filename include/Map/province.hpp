#include <iostream>
#include <Engine/vector2.hpp>
#include <SDL2/SDL_image.h>

#pragma once

struct Province
{
public:
    Province(int index, int r, int g, int b, std::string name)
    {
        this->index = index;
        this->r = r;
        this->g = g;
        this->b = b;
        this->name = name;
    };

    //index of the province
    int index;
    //color values in province map
    int r, g, b;
    //name of the province
    std::string name;
    //stores all the x and y positions of this province's pixels on the map
    std::vector<Vector2 *> pixels;

    void changeColor(SDL_Surface *map, int r, int g, int b);
};