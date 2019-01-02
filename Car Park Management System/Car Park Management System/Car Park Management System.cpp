// Car Park Management System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Manage.h"
int main()
{
	//input string
	std::string input;
	std::getline(std::cin, input);
	//insatnce of Manage passing s, can be empty for default constructor for test string
	//set ticket
	Manage *manage = new Manage(input);
	//processes string
	manage->processTicket();
	//prints state of car park
	manage->printCarPark();

}