#pragma once
#define level_width 24
#define level_height 15

class Level {

    public:
        int size [level_width][level_height];
        Level();
        ~Level(); 
};