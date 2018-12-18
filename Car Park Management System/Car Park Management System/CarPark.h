#pragma once
#include <string>
#include <iostream>
#include "Space.h"
class CarPark
{
private:
	Space *spaces[10];
	int freeSpaces = 10;
	int ticketstart;
public:
	CarPark(int ti);
	~CarPark();
	bool addSpace(std::string s);
	bool removeSpace(int tID);
	void print();
	void shuffle();
};


