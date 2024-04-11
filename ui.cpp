#include <vector>
#include <string>
#include <optional>
#include "error.hpp"
#include "globals.hpp"
#include "ui.hpp"

static std::optional<int> getInt(){
	Logger logger;
	std::string inp,raw;
	std::optional<int> ret;
	std::getline(std::cin, raw);
	for(int i = 0; i < raw.size(); i++){
		if(raw[i] == ' ')
			continue;
		inp += std::toupper(raw[i]);
	}
	try{
		ret = stoi(inp);
	}
	catch(std::invalid_argument){
		return ret;
	}
	return ret;
}

static std::optional<bool> getBool(){
	Logger logger;
	std::string inp,raw;
	std::optional<bool> ret;
	std::getline(std::cin, raw);
	for(int i = 0; i < raw.size(); i++){
		if(raw[i] == ' ')
			continue;
		inp += std::toupper(raw[i]);
	}
	if(inp == "Y")
		ret = true;
	if(inp == "YES")
		ret = true;
	if(inp == "TRUE")
		ret = true;
	if(inp == "T")
		ret = true;
	if(inp == "N")
		ret = false;
	if(inp == "NO")
		ret = false;
	if(inp == "FALSE")
		ret = false;
	if(inp == "F")
		ret = false;
	return ret;
}
static void setBool(bool *ret){
	Logger logger;
	auto input = getBool();
	if(input.has_value()){
		logger.log("changed to " + std::to_string(input.value()), Logger::DEBUG);
		(*ret) = input.value();
	}
}
static void setInt(int *ret){
	Logger logger;
	auto input = getInt();
	if(input.has_value()){
		logger.log("changed to " + std::to_string(input.value()), Logger::DEBUG);
		(*ret) = input.value();
	}
}
void updateSettings(){
	Logger logger;
	logger.log("Enable ranked friends? (current: " + std::string(RANKED_FRIENDS ? "true" : "false") + std::string(", press enter to skip)"), Logger::INFO);
	setBool(&RANKED_FRIENDS);
	logger.log("Use groups? (current: " + std::string(USE_LINK_MAP ? "true" : "false") + std::string(", press enter to skip)"), Logger::INFO);
	setBool(&USE_LINK_MAP);
	logger.log("Maximize misery? (current: " + std::string(MAXIMIZE_MISERY ? "true" : "false") + std::string(", press enter to skip)"), Logger::INFO);
	setBool(&MAXIMIZE_MISERY);
	logger.log("Change max group size / x dimension? (current: " + std::to_string(SIZE_X) + std::string(", press enter to skip)"), Logger::INFO);
	setInt(&SIZE_X);
	logger.log("Change number of groups / y dimension? (current: " + std::to_string(SIZE_Y) + std::string(", press enter to skip)"), Logger::INFO);
	setInt(&SIZE_Y);
	logger.log("Change number of permutations per generation? (current: " + std::to_string(PERMS) + std::string(", press enter to skip)"), Logger::INFO);
	setInt(&PERMS);
	logger.log("Change size of permutations? (current: " + std::to_string(DIFF) + std::string(", press enter to skip)"), Logger::INFO);
	setInt(&DIFF);
	logger.log("Change number of generations? (current: " + std::to_string(GENERATIONS) + std::string(", press enter to skip)"), Logger::INFO);
	setInt(&GENERATIONS);
}
std::vector<std::string> getFileAsInput(){
	Logger logger;
	int i = 0;
	std::vector<std::string> ret;
	std::string temp;
	while(true){
		logger.log("Input person " + std::to_string(++i) + "'s name (e to end input):", Logger::INFO);
		temp.clear();
		std::getline(std::cin,temp);
		if(temp.size() == 0)
			return ret;
		if(temp == "e")
			return ret;
		ret.push_back(temp);
		logger.log("Input " + temp + "'s friends (comma seperated, no spaces):", Logger::INFO);
		temp.clear();
		std::getline(std::cin,temp);
		ret[i - 1] += "," + temp;
	}
}
