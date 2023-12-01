#include <vector>
#include "person.hpp"
#include "globals.hpp"
class SeatingConfig{
	int sum;
public:
	Spot config[SIZE_X * SIZE_Y];
	Spot& twoDim(const int x, const int y){ return config[SIZE_X * y + x]; }
	void linkPeople();
	int getHappiness(bool regen = false);
	void output();
};
SeatingConfig spotsToConfig(std::vector<std::vector<Spot>>);
bool genNextConfig(SeatingConfig& ret, const int numPeople, const std::vector<Person>& people);
