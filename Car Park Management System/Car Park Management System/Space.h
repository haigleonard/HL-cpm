#pragma once
#include <string>
#include <iostream>
class Space
{
private:
	std::string noPlate;
	int ticketNumber;
	bool empty;
public:
	Space();
	Space(std::string s, int n);
	~Space();
	std::string getnoPlate();
	int getticketNumber();
	void clear();
	bool getempty();

};

