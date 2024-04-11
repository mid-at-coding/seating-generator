#include "read.hpp"
static std::vector<std::string> getData(std::string filename){
	std::ifstream file;
	file.open(filename);
	std::vector<std::string> data;
	std::string currentLine;
	if (file.is_open()) {
		while (getline(file, currentLine)) {
			while (currentLine.find("\r") != std::string::npos) {
				currentLine.erase(currentLine.find("\r"), 1);
			}
			data.push_back(currentLine);
		}
	}
	file.close();

	return data;
}

static std::vector<std::string> splitString(std::string input){
	// split a line by commas
	std::vector<std::string> ret;
	std::string currentPart;
	for (int i = 0; i < input.size(); i++){
		currentPart += input[i];
		if(input[i] == ','){
			currentPart.pop_back();
			ret.push_back(currentPart);
			currentPart.clear();
			continue;
		}
	}
	ret.push_back(currentPart);
	currentPart.clear();
	return ret;
}

void file::read(const std::vector<std::string> & buf){
	auto rawData = buf;
	std::vector<std::string> currentLine;
	int person = 0;
	
	// name,friend1,friend2, ...

	for(int y = 0; y < rawData.size(); y++){
		// go line by line
		currentLine = splitString(rawData[y]);
		// map a name to their friends (the rest of the line)
		friends_list[currentLine[0]] = std::vector<std::string>(currentLine.begin() + 1, currentLine.end());
		// add the person to names and name_map
		names.push_back(currentLine[0]);
		name_map[currentLine[0]] = person++;
	}
}
void file::read(std::string filename){
	auto rawData = getData(filename);
	std::vector<std::string> currentLine;
	int person = 0;
	
	// name,friend1,friend2, ...

	for(int y = 0; y < rawData.size(); y++){
		// go line by line
		currentLine = splitString(rawData[y]);
		// map a name to their friends (the rest of the line)
		friends_list[currentLine[0]] = std::vector<std::string>(currentLine.begin() + 1, currentLine.end());
		// add the person to names and name_map
		names.push_back(currentLine[0]);
		name_map[currentLine[0]] = person++;
	}
}
