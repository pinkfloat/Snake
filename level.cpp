#include "level.hpp"

Level::Level(){
	for ( int x = 0; x < level_width; x++){
		for ( int y = 0; y < level_height; y++){
			if ( ( x == 0) || ( x == level_width-1) ) //seitliche Spielfeldbegrenzung
				field[x][y] = fieldCondition::WALL;
			else if ( ( y == 0) || ( y == level_height-1) ) //obere und untere Spielfeldbegrenzung
				field[x][y] = fieldCondition::WALL;
			else
				field[x][y] = fieldCondition::EMPTY;
		}
	}
}

Level::~Level(){
}

//Beendet Spiel bei Collision mit Wand oder Schlangenkoerper
bool Level::checkCollision( SnakeHead* player, Window* window){
	if ( field [player->x][player->y] == fieldCondition::EMPTY)
		return true;
	else if ( field [player->x][player->y] == fieldCondition::APPLE){
			//Schlange vergroeßern
			SnakePart* newPart = new SnakePart(player->x, player->y, player->dir, window);
			player->addSnakePart(newPart);
			//Apfel umplatzieren
			/* code */

		return true;
	}
	else
		return false;
}