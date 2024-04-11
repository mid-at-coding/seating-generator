#include "globals.hpp"
#include <map>
int NUM_PEOPLE = 0;
int SIZE_X = 2;
int SIZE_Y = 5;
bool RANKED_FRIENDS = false;
int PERMS = 1;
int GENERATIONS = 100000;
bool USE_LINK_MAP = true;
int DIFF = 1;
bool MAXIMIZE_MISERY = false;
std::map<int, std::map<int, std::vector<Person*>>> LINKS;
