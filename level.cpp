#include "level.hpp"

Level::Level(){
	for ( int x = 0; x < level_width; x++){
		for ( int y = 0; y < level_height; y++){
			if ( ( x == 0) || ( x == level_width-1) ) //seitliche Spielfeldbegrenzung
				size[x][y] = 2;
			else if ( ( y == 0) || ( y == level_height-1) ) //obere und untere Spielfeldbegrenzung
				size[x][y] = 2;
			else
				size[x][y] = 0;
		}
	}
}

Level::~Level(){

}