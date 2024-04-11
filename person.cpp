#include "person.hpp"
#include "globals.hpp"
#include "error.hpp"
int Person::num = 0;

Spot::Spot(bool empty, const int x, const int y){
	Logger logger;
	person = new Person("empty");
	(*person).empty = true;
	(*person).name = "empty";
	(*this).x = x;
	(*this).y = y;
}

Spot::Spot(Person& p, const int x, const int y){
	person = &p;
	(*this).x = x;
	(*this).y = y;
}
int Spot::getX(){
	return x;
}

int Spot::getY(){
	return y;
}

void Person::setFriends(const std::vector<int> fs){
	friends = fs;
}

int Person::getHappiness(){
	if(empty)
		return 0;
	happiness = 0;
	for(int i = 0; i < friends.size(); i++){
		for(int j = 0; j < neighbours.size(); j++){
			if(friends[i] == neighbours[j]->getID())
				happiness += RANKED_FRIENDS ? friends.size() - i : 1;
		}
	}
	return happiness;
}

int Person::getID(){
	if(empty)
		return -1;
	return id;
}

std::string Person::getName(){
	if(empty)
		return "empty";
	return name;
}
