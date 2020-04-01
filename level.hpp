#pragma once
#include "snakehead.hpp"

#define level_width 23
#define level_height 15

/* 'Level' is the game screen as array where apple, snake and walls are placed in */

enum class fieldCondition {
	EMPTY, APPLE, SNAKE, WALL
};

class Level {
    public:
        fieldCondition field[level_width][level_height];
        Level(SnakeHead* player, GameObject* apple);

        void updateMap(SnakeHead* player, GameObject* apple);
        bool checkCollision(SnakeHead* player, GameObject* apple, Window* window);
        void replaceApple(SnakeHead* player, GameObject* apple);
};