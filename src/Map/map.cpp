#include <Map/map.hpp>
#include <Map/map_renderer.hpp>
#include <fstream>
#include <Engine/vector2.hpp>

void Map::init()
{
    renderer = new MapRenderer(game);
    renderer->init();

    parseProvinces("map/definition.csv");
}

void Map::update()
{

}

void Map::render()
{
    renderer->render();
}

void Map::parseProvinces(std::string path)
{
    std::ifstream file;
    file.open(path);
    if (!file.is_open())
        perror("parseProvinces: coulnd't open the file!");
    else
    {
        std::string line;
        while (std::getline(file, line))
        {

            //splitting line into seperate properties based on ';'
            try
            {
                float id = std::stof(line.substr(0, line.find(";")));
                line.erase(0, line.find(";") + 1);

                int r = std::stoi(line.substr(0, line.find(";")));
                line.erase(0, line.find(";") + 1);

                int g = std::stoi(line.substr(0, line.find(";")));
                line.erase(0, line.find(";") + 1);

                int b = std::stoi(line.substr(0, line.find(";")));
                line.erase(0, line.find(";") + 1);

                std::string name = line.substr(0, line.find(";"));

                //create new province with parsed values
                Province *province = new Province(id, r, g, b, name);

                //store the province
                // this->provinces.push_back(province);
                provinces[provincesLength] = province;
                provincesLength++;

                //for debugging purposes
                // std::cout << "id: " << id << ", r,g,b: " << r << "," << g << "," << b << ", name: " << name << std::endl;
            }
            catch (const std::exception &e)
            {
            }
        }
        file.close();

        std::cout << "Parsed " << provincesLength << " provinces." << std::endl;
    }
}