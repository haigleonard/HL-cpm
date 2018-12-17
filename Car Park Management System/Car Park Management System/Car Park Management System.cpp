// Car Park Management System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Manage.h"
int main()
{
	//input string
	std::string ticket;
	std::getline(std::cin, ticket);
	//insatnce of Manage passing s, can be empty for default constructor for test string
	//set ticket
	Manage *manage = new Manage();
	manage->processTicket();
}
