#ifndef GLOBAL_H
#define GLOBAL_H
#include "person.hpp"
#include <vector>
#include <map>
extern bool MAXIMIZE_MISERY;
extern int NUM_PEOPLE;
extern int SIZE_X;
// ^^ num of groups
extern int SIZE_Y;
extern bool RANKED_FRIENDS;
extern int PERMS;
extern int GENERATIONS;
extern bool USE_LINK_MAP;
extern int DIFF;
extern std::map<int, std::map<int, std::vector<Person*>>> LINKS;
// extern std::vector<Person*> LINKS[SIZE_X][SIZE_Y];
#endif
