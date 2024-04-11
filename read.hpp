#ifndef READ_H
#define READ_H
#include "person.hpp"
#include <map>
#include <fstream>
#include <iostream>
class file{
public:
	std::map<std::string, int> name_map;
	std::vector<std::string> names;
	std::map<std::string, std::vector<std::string>> friends_list;
	void read(std::string filename);
	void read(const std::vector<std::string> & buf);
};

#endif
