#include "gen.hpp"
#include "globals.hpp"
#include "read.hpp"
#include "links.hpp"
#include "ui.hpp"
#include <iostream>
#include <iomanip>
#include <map>
#include "error.hpp"

int main(int argc, char* argv[]){
	Logger logger;
	file friendos; 
	Logger::outputThreshold = Logger::INFO;
	if(argc == 1) // interactive mode
		friendos.read(getFileAsInput());
	else // file supplied by user
        friendos.read(std::string(argv[1]));
	updateSettings();
	NUM_PEOPLE = friendos.names.size();
	std::vector<Person> people;
	std::vector<Spot> temp_row;
	SeatingConfig spots;
	// init people
	for(int i = 0; i < friendos.names.size(); i++){
		people.push_back(Person(friendos.names[i]));
	}
	// init friends
	for(int i = 0; i < friendos.names.size(); i++){
		for(int j = 0; j < friendos.friends_list[friendos.names[i]].size(); j++){
			people[i].friends.push_back(friendos.name_map[friendos.friends_list[friendos.names[i]][j]]);	
		} 
	}
	// check friends
	for(int i = 0; i < friendos.names.size(); i++){
		logger.log(friendos.names[i], Logger::DEBUG);
		for(int j = 0; j < people[i].friends.size(); j++){
			logger.log(friendos.names[people[i].friends[j]], Logger::DEBUG, 1);
		}
	}
	// set up initial seatingconfig
	for(int y = 0; y < SIZE_Y; y++){
		for(int x = 0; x < SIZE_X; x++){
			spots.twoDim(x,y) = Spot(people[SIZE_X * y + x], x, y);
			if(SIZE_X * y + x >= NUM_PEOPLE)
				spots.twoDim(x,y) = Spot(false, x, y);
		}
	}
	initLinks(spots);
	spots.linkPeople();
	logger.log("Happiness: " + std::to_string(spots.getHappiness(true)), Logger::INFO);
	spots.output();
	for(int i = 0; i < GENERATIONS; i++){
		if(genNextConfig(spots, SIZE_X * SIZE_Y, people)){
			logger.log("New " + (MAXIMIZE_MISERY ? std::string("worst") : std::string("best")) + " config found: gen: " + std::to_string(i), Logger::INFO);
			logger.log("Happiness: " + std::to_string(spots.getHappiness(true)), Logger::INFO);
			spots.output();
		}
	}
}
