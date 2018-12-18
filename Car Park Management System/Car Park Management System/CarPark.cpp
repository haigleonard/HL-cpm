#include "pch.h"
#include "CarPark.h"

// pass ticket number in constructor, assign ticket start to passed value(5000)
CarPark::CarPark(int tick) { 
	ticketstart = tick; 
	for (int i = 0; i < 10; i++) 
		spaces[i] = new Space(); 
};

CarPark::~CarPark()
{
}

bool CarPark::addSpace(std::string s) {
	//if there are no spaces, break
	if (freeSpaces == 0)  return false;
	//cycle through the ten spaces, if empty add current ticketID count and reg no. ticket ++, return true to end for loop;
	for (int i = 0; i < 10; i++) {
		if (spaces[i]->getempty())
		{
			spaces[i] = new Space(s, ticketstart); freeSpaces--; ticketstart++;
			return true;
		}
	}
	return false;
}

bool CarPark::removeSpace(int tID)
{
	//if there are no cars/10 free spaces return
	if (freeSpaces == 10) return false;
	//cycloe through 10 spaces, if ticketID referenced is equal to space[i], clear and add to freespaces
	for (int i = 0; i < 10; i++) {
		if (spaces[i]->getticketNumber() == tID)
		{
			spaces[i]->clear();
			freeSpaces++;
			return true;
		}
	}
	return false;
}

void CarPark::shuffle()
{
	// cycle from first to second from last and check is space is empty
	for (int i = 0; i < 9; i++) {
		if (spaces[i]->getempty())
		{
			//cycle through from i to find next position that is not empty and move it to i. clear space, e = 9 to end inner for loop
			for (int e = i + 1; e < 9 - i; e++) {
				if (!spaces[e]->getempty())
				{
					*spaces[i] = *spaces[e];
					spaces[e]->clear();
					e = 9;
				}
			}

		}
	}
}

void CarPark::print() 
{ 
	//print each space number plate
	for (int i = 0; i < 10; i++)
		std::cout << spaces[i]->getnoPlate() << ",";  
}