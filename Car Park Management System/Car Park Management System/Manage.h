#pragma once
#include <string>
#include "CarPark.h"
class Manage
{
private:
	CarPark *carpark;
	std::string ticket = "pABC, pXYZ, u5001, u5000, c, pOOO, u5004, c";
public:
	//default to use test string
	Manage() { carpark = new CarPark(5000); };
	// sets tickets
	Manage(std::string s) : ticket(s) { carpark = new CarPark(5000); };
	~Manage();
	void processTicket();
};

