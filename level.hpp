#pragma once
#define level_width 24
#define level_height 15

#include "gameobjects.hpp"

enum class fieldCondition {
	EMPTY, APPLE, SNAKE, WALL
};

class Level {

    public:
        fieldCondition field [level_width][level_height];
        Level();
        ~Level();

        bool checkCollision(SnakeHead* player, GameObject* apple, Window* window); 
};