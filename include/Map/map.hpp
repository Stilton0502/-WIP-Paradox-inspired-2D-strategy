#include <iostream>
#include <vector>
#include <Engine/game.hpp>
#include <Map/province.hpp>
#include <SDL2/SDL_image.h>

#define NUM_PROVINCES 3248

#pragma once

class MapRenderer;

//this class represents the abstract class of the entire map and all it's components are stored in here
class Map
{
private:
    Engine::Game *game;

    //pointer to the renderer of the map
    MapRenderer *renderer;

    //all provinces of the map
    Province* provinces[NUM_PROVINCES];
    int provincesLength = 0;

public:
    Map(Engine::Game *game){this->game = game;};

    void init();

    void update();

    void render();

    //parses all provinces from the file at the path (by default this is: map/definition.csv)
    void parseProvinces(std::string path);

    //extracts all colors of the color map and creates different textures for each single color with all it's pixels on the color map
    void createProvinceTextures(std::string colorMapPath);

    Province** getProvinces(){return provinces;};
    int getProvincesLength(){return provincesLength;};
};