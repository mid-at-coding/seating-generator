#include "person.hpp"
int Person::num = 0;

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
	happiness = 0;
	for(int i = 0; i < friends.size(); i++){
		if(leftSet)
			if(friends[i] == left->getID())
				happiness += (friends.size() - i + 1);

		if(rightSet)
			if(friends[i] == right->getID())
				happiness += (friends.size() - i + 1);

		if(upSet)
			if(friends[i] == up->getID())
				happiness += (friends.size() - i + 1);
		
		if(downSet)
			if(friends[i] == down->getID())
				happiness += (friends.size() - i + 1);
		
	}
	return happiness;
}

int Person::getID(){
	return id;
}

std::string Person::getName(){
	return name;
}
