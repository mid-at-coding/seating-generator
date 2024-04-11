#include "gen.hpp"
#include <iomanip>
#include <random>
#define MAX_NUM 5
SeatingConfig spotsToConfig(std::vector<std::vector<Spot>>);
void SeatingConfig::linkPeople(){
	if(!USE_LINK_MAP){
		for(int y = 0; y < SIZE_Y; y++){
			for(int x = 0; x < SIZE_X; x++){
				twoDim(x, y).person->neighbours.clear();
				if(x < SIZE_X - 1)
					twoDim(x, y).person->neighbours.push_back(twoDim(x + 1, y).person);

				if(x > 0)
					twoDim(x, y).person->neighbours.push_back(twoDim(x - 1, y).person);
				

				if(y < SIZE_Y - 1)
					twoDim(x, y).person->neighbours.push_back(twoDim(x, y + 1).person);

				if(y > 0)
					twoDim(x, y).person->neighbours.push_back(twoDim(x, y - 1).person);
			}
		}
		return;
	}
	for(int y = 0; y < SIZE_Y; y++){
		for(int x = 0; x < SIZE_X; x++){
			twoDim(x, y).person->neighbours.clear();
			twoDim(x, y).person->neighbours = LINKS[x][y];
		}
	}
}
int SeatingConfig::getHappiness(bool regen){
	Logger logger;
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
		for(int j = 0; j < DIFF; j++){
			first = distrib(gen);
			second = distrib(gen);

			temp = next[i].config[first].person;
			next[i].config[first].person = next[i].config[second].person;
			next[i].config[second].person = temp;
		}
		next[i].linkPeople();
		next[i].getHappiness(true);
		ret.linkPeople();
		ret.getHappiness(true);
		if ((next[i].getHappiness() > ret.getHappiness() && !MAXIMIZE_MISERY) || (next[i].getHappiness() < ret.getHappiness() && MAXIMIZE_MISERY)){
			changed = true;
			next[i].linkPeople();
			ret = next[i];
		}
	}
	return changed;
}

void SeatingConfig::output(){
	for(int y = 0; y < SIZE_Y; y++){
		if(USE_LINK_MAP)
			std::cout << "group: " << y + 1;
		for(int x = 0; x < SIZE_X; x++){
			std::cout << std::setw(10) << (*twoDim(x, y).person).getName() << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
