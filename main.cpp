#include "gen.hpp"
#include <iostream>
#include <iomanip>
#include <map>

int main(){
	std::vector<std::string> names{
		"emelia",
		"benjamin",
		"kaia",
		"nina",
		"david",
		"jonas",
		"penelope",
		"charlotte",
		"ariana",
		"seth"
	};
	std::map<std::string, int> name_map;
	std::vector<std::vector<std::string>> friends_list{
		{"benjamin","david"},
		{"emelia","nina"},
		{"david","jonas"},
		{"penelope","benjamin"},
		{"seth","charlotte"},
		{"ariana","penelope"},
		{"nina","david"},
		{"kaia","nina"},
		{"seth","benjamin"},
		{"jonas","ariana"}
	};
	std::vector<Person> people;
	std::vector<Spot> temp_row;
	SeatingConfig spots;
	for(int i = 0; i < names.size(); i++){
		people.push_back(Person(names[i]));
		name_map[names[i]] = i;
	}
	for(int i = 0; i < names.size(); i++){
		for(int j = 0; j < friends_list[i].size(); j++){
			people[i].friends.push_back(name_map[friends_list[i][j]]);	
		}
	}
	for(int y = 0; y < SIZE_Y; y++){
		for(int x = 0; x < SIZE_X; x++){
			spots.twoDim(x,y) = Spot(people[SIZE_X * y + x], x, y);
		}
	}
	spots.linkPeople();
	for(int i = 0; i < GENERATIONS; i++){
		if(genNextConfig(spots, 10, people)){
			std::cout << "Happiness: " << spots.getHappiness() << std::endl;
			spots.output();
		}
	}
}
