#ifndef PERSON_H
#define PERSON_H
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
	Spot(bool, const int, const int);
	int getX();
	int getY();
};
class Person{
	static int num;
	int id;
	int happiness;
public:
	bool empty = false;
	std::string name;
	std::vector<Person*> neighbours;
	std::vector<int> friends;
	Person(const std::string& n){
		id = num++;
		name = n;
	}
	Person(){
		id = num++;
	}
	void setFriends(const std::vector<int> fs);
	int getHappiness();
	int getID();
	std::string getName();
};
#endif
