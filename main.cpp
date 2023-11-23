#include "person.hpp"
#include <iostream>
#include <iomanip>
#include <map>

int main(){
	const int length = 5;
	const int width = 2;
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
	// set up square grid. somehow
	std::vector<Person> people;
	std::vector<std::vector<Spot>> spots;
	std::vector<Spot> temp_row;
	for(int i = 0; i < names.size(); i++){
		people.push_back(Person(names[i]));
		name_map[names[i]] = i;
	}
	for(int i = 0; i < names.size(); i++){
		for(int j = 0; j < friends_list[i].size(); j++){
			people[i].friends.push_back(name_map[friends_list[i][j]]);	
		}
	}
	for(int y = 0; y < width; y++){
		for(int x = 0; x < length; x++){
			temp_row.push_back(Spot(people[length * y + x], x, y));
			std::cout << "[" << std::setw(1) <<  length * y + x << "]";
		}
		spots.push_back(temp_row);
		std::cout << std::endl;
	}
	for(int y = 0; y < width; y++){
		for(int x = 0; x < length; x++){ // rewrite with spots
			if(x < length - 1)
				spots[x][y].person->right = spots[x + 1][y].person;
			else
				spots[x][y].person->right = spots[x][y].person;

			if(x > 0)
				spots[x][y].person->left = spots[x - 1][y].person;
			else
				spots[x][y].person->left = spots[x][y].person;

			if(y < width - 1)
				spots[x][y].person->down = spots[x][y + 1].person;
			else
				spots[x][y].person->down = spots[x][y].person;

			if(y > 0)
				spots[x][y].person->up = spots[x][y - 1].person;
			else
				spots[x][y].person->up = spots[x][y].person;
		}
	}
	for(int i = 0; i < people.size(); i++){
		std::cout << "Person: " << i << "(" << people[i].getName() << ")" << std::endl;
		std::cout << "	left:" << people[i].left->getID() << "(" << people[i].left->getName() << ")" << std::endl;
		std::cout << "	right:" << people[i].right->getID() << "(" << people[i].right->getName() << ")" << std::endl;
		std::cout << "	down:" << people[i].down->getID() << "(" << people[i].down->getName() << ")" << std::endl;
		std::cout << "	up:" << people[i].up->getID() << "(" << people[i].up->getName() << ")" << std::endl;
		std::cout << "	happiness:" << people[i].getHappiness() << std::endl;
	}
}
