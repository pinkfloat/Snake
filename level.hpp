#pragma once
#define level_width 22
#define level_height 14

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
        void replaceApple (SnakeHead* player, GameObject* apple);
};