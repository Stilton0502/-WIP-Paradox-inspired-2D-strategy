#include <iostream>

#pragma once

namespace Map{

    class MapRenderer;
    
    //this class represents the abstract class of the entire map and all it's components are stored in here
    class Map{
        private:
            //pointer to the renderer of the map
            MapRenderer *renderer;
        public:
    };
}