#include "gen.hpp"
void initLinks(SeatingConfig spots){
	// do groups of SIZE_X
	for(int y = 0; y < SIZE_Y; y++){
		for(int x = 0; x < SIZE_X; x++){
			for(int x2 = 0; x2 < SIZE_X; x2++){
				LINKS[x][y].push_back(spots.twoDim(x2, y).person);
			}
		}
	}
}
