#include "gen.hpp"
#include <iomanip>
#include <random>
#define MAX_NUM 5
SeatingConfig spotsToConfig(std::vector<std::vector<Spot>>);
void SeatingConfig::linkPeople(){
	for(int y = 0; y < SIZE_Y; y++){
		for(int x = 0; x < SIZE_X; x++){
			if(x < SIZE_X - 1){
				twoDim(x, y).person->right = twoDim(x + 1, y).person;
				twoDim(x, y).person->rightSet = true;
			}
			else{
				twoDim(x, y).person->right = twoDim(x, y).person;
				twoDim(x, y).person->rightSet = false;
			}

			if(x > 0){
				twoDim(x, y).person->left = twoDim(x - 1, y).person;
				twoDim(x, y).person->leftSet = true;
			}
			else{
				twoDim(x, y).person->left = twoDim(x, y).person;
				twoDim(x, y).person->leftSet = false;
			}
			

			if(y < SIZE_Y - 1){
				twoDim(x, y).person->down = twoDim(x, y + 1).person;
				twoDim(x, y).person->downSet = true;
			}
			else{
				twoDim(x, y).person->down = twoDim(x, y).person;
				twoDim(x, y).person->downSet = false;
			}

			if(y > 0){
				twoDim(x, y).person->up = twoDim(x, y - 1).person;
				twoDim(x, y).person->upSet = true;
			}
			else{
				twoDim(x, y).person->up = twoDim(x, y).person;
				twoDim(x, y).person->upSet = false;
			}
		}
	}
}
int SeatingConfig::getHappiness(bool regen){
	if(!regen)
		return sum;
	sum = 0;
	for(int i = 0; i < SIZE_X * SIZE_Y; i++){
		sum += config[i].person->getHappiness();
	}
	return sum;
}
bool genNextConfig(SeatingConfig& ret, const int numPeople, const std::vector<Person>& people){
	SeatingConfig current = ret;
	bool changed = false;
	Person* temp;
	int first,second;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, SIZE_X * SIZE_Y - 1);
	SeatingConfig next[PERMS];
	ret.linkPeople();
	ret.getHappiness(true);
	for(int i = 0; i < PERMS; i++){
		next[i] = current;
		first = distrib(gen);
		second = distrib(gen);

		temp = next[i].config[first].person;
		next[i].config[first].person = next[i].config[second].person;
		next[i].config[second].person = temp;
		
		next[i].linkPeople();
		next[i].getHappiness(true);
		ret.linkPeople();
		ret.getHappiness(true);
		if (next[i].getHappiness() > ret.getHappiness()){
			changed = true;
			next[i].linkPeople();
			ret = next[i];
		}
	}
	return changed;
}

void SeatingConfig::output(){
	for(int y = 0; y < SIZE_Y; y++){
		for(int x = 0; x < SIZE_X; x++){
			std::cout << std::setw(10) << twoDim(x, y).person->name << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
