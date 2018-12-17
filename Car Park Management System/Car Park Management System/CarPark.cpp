#include "pch.h"
#include "CarPark.h"

CarPark::CarPark(int tick) { ticketID = tick; for (int i = 0; i < 10; i++) spaces[i] = new Space(); };

CarPark::~CarPark()
{
}

bool CarPark::addSpace(std::string s) {
	if (freeSpaces == 0) { return false; }
	for (int i = 0; i < 10; i++)
	{
		if (spaces[i]->getempty())
		{
			spaces[i] = new Space(s, ticketID); freeSpaces--; ticketID++; i = 10;
			return true;
		}
	}
	return false;
}

bool CarPark::removeSpace(int tID)
{
	if (freeSpaces == 10) { return false; }
	for (int i = 0; i < 10; i++)
	{
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
	for (int i = 0; i < 9; i++)
	{
		if (spaces[i]->getempty())
		{
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