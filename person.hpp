#include <set>
#include <vector>
#include <string>
#include <iostream>
class Person;
class Spot{
	int x,y;
public:
	Person* person;
	Spot(Person p, int x, int y);
	int getX();
	int getY();
};
class Person{
	static int num;
	std::string name;
	int id;
	int happiness;
public:
	Person* left;
	Person* right;
	Person* up;
	Person* down;
	std::vector<int> friends;
	Person(const std::string n){
		left = this;
		right = this;
		up = this;
		down = this;
		id = num++;
		name = n;
	}
	void setFriends(const std::vector<int> fs);
	int getHappiness();
	int getID();
	std::string getName();
};

