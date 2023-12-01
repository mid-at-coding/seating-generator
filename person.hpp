#include <set>
#include <vector>
#include <string>
#include <iostream>
class Person;
class Spot{
	int x,y;
public:
	Person* person;
	Spot(Person& p, const int x, const int y);
	Spot() {}
	int getX();
	int getY();
};
class Person{
	static int num;
	int id;
	int happiness;
public:
	std::string name;
	bool leftSet;
	bool rightSet;
	bool upSet;
	bool downSet;
	Person* left;
	Person* right;
	Person* up;
	Person* down;
	std::vector<int> friends;
	Person(const std::string& n){
		leftSet = false;
		rightSet = false;
		downSet = false;
		upSet = false;
		id = num++;
		name = n;
	}
	Person(){
		leftSet = false;
		rightSet = false;
		downSet = false;
		upSet = false;
		id = num++;
	}
	void setFriends(const std::vector<int> fs);
	int getHappiness();
	int getID();
	std::string getName();
};

