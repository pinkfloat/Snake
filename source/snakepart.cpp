/*
*   Copyright: (c) 2020 Sabrina Otto. All rights reserved.
*   This work is licensed under the terms of the MIT license.
*/

#include "snakepart.hpp"
#include "image.hpp"

SnakePart::SnakePart(int partX, int partY, Direction dir, Window* window)
: GameObject(partX, partY, window), dir(dir), oldDir(dir)
{} 

void SnakePart::getBodyImage() {
	switch(dir) {
		case Direction::UP:		
			switch(oldDir) {
				case Direction::UP:
				case Direction::DOWN:	imagePosition = TUpDown; 	break;
				case Direction::RIGHT:	imagePosition = TUpLeft;	break;
				case Direction::LEFT:	imagePosition = TUpRight; 	break;
			}
		break;
		case Direction::RIGHT:
			switch(oldDir) {
				case Direction::UP:		imagePosition = TDownRight; break;
				case Direction::RIGHT:
				case Direction::LEFT:	imagePosition = TLeftRight;	break;
				case Direction::DOWN:	imagePosition = TUpRight;	break;
			}
		break;
		case Direction::DOWN:
			switch(oldDir) {
				case Direction::UP:
				case Direction::DOWN:	imagePosition = TUpDown;	break;
				case Direction::RIGHT:	imagePosition = TLeftDown;	break;
				case Direction::LEFT:	imagePosition = TDownRight;	break;
			}
		break;
		case Direction::LEFT:
			switch(oldDir) {
				case Direction::UP:		imagePosition = TLeftDown;	break;
				case Direction::RIGHT:
				case Direction::LEFT:	imagePosition = TLeftRight;	break;
				case Direction::DOWN:	imagePosition = TUpLeft;	break;
			}
		break;
		default: 						imagePosition = TApple;		break;
	}
}

void SnakePart::getTailImage() {
	switch(dir) {
		case Direction::UP:		imagePosition = TTailUp;	break;
		case Direction::RIGHT:	imagePosition = TTailRight;	break;
		case Direction::DOWN:	imagePosition = TTailDown;	break;
		case Direction::LEFT:	imagePosition = TTailLeft;	break;
		default:				imagePosition = TApple;		break;
	}
}
