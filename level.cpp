#include "level.hpp"
#include <cstdlib>
#include <ctime>

Level::Level(){
	for ( int x = 0; x < level_width; x++){
		for ( int y = 0; y < level_height; y++){
			if ( ( x == 0) || ( x == level_width) ) //seitliche Spielfeldbegrenzung
				field[x][y] = fieldCondition::WALL;
			else if ( ( y == 0) || ( y == level_height) ) //obere und untere Spielfeldbegrenzung
				field[x][y] = fieldCondition::WALL;
			else
				field[x][y] = fieldCondition::EMPTY;
		}
	}
}

Level::~Level(){
}

//Beendet Spiel bei Collision mit Wand oder Schlangenkoerper
bool Level::checkCollision( SnakeHead* player, GameObject* apple, Window* window){
	if ( field [player->x][player->y] == fieldCondition::EMPTY)
		return true;
	else if ( field [player->x][player->y] == fieldCondition::APPLE){
			//Schlange vergroeßern
			SnakePart* newPart = new SnakePart(player->x, player->y, player->dir, window);
			player->addSnakePart(newPart);
			//Apfel umplatzieren
			replaceApple(player, apple);
		return true;
	}
	else
		return false;
}

void Level::replaceApple( SnakeHead* player, GameObject* apple){
	//Vermeiden, dass Apfel in der Schlange spawnt:
	bool spawnInPlayer = false;
	do{
		spawnInPlayer = false;
		std::srand(time(nullptr)); //aktuelle Zeit verwenden fuer Random-Generator
		apple->x = rand() % 21 + 1;
		apple->y = rand() % 13 + 1;
		
		if ((player->x == apple->x)&&(player->y == apple->y))
			spawnInPlayer = true;
		else{
			for ( auto actualPart : player->Parts){
				if ((actualPart->x == apple->x)&&(actualPart->y == apple->y))
					spawnInPlayer = true;
			}
		}
	} while (spawnInPlayer);
}