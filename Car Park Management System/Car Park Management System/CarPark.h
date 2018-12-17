#pragma once
#include <string>
#include <iostream>
#include "Space.h"
class CarPark
{
private:
	Space *spaces[10];
	int freeSpaces = 10;
	int ticketID;
public:
	CarPark(int ti);
	~CarPark();
	bool addSpace(std::string s);
	bool removeSpace(int tID);
	void print() { for (int i = 0; i < 10; i++) { std::cout << spaces[i]->getnoPlate() << ","; } }
	void shuffle();
};


