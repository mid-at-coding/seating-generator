#ifndef GEN_H
#define GEN_H
#include <vector>
#include "person.hpp"
#include "error.hpp"
#include "globals.hpp"
class SeatingConfig{
	int sum;
public:
	std::vector<Spot> config;
	SeatingConfig(){
		for(int i = 0; i < SIZE_X * SIZE_Y; i++){
			if(i >= NUM_PEOPLE)
				config.push_back(Spot(true, 0, 0));
			config.push_back(Spot());
		}
	}
	Spot& twoDim(const int x, const int y){ return config[SIZE_X * y + x]; }
	void linkPeople();
	int getHappiness(bool regen = false);
	void output();
};
SeatingConfig spotsToConfig(std::vector<std::vector<Spot>>);
bool genNextConfig(SeatingConfig& ret, const int numPeople, const std::vector<Person>& people);
#endif
