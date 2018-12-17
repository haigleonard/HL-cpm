#include "pch.h"
#include "Space.h"



Space::Space() { noPlate = ""; ticketNumber = 0; empty = true; };
Space::Space(std::string s, int n) { noPlate = s; ticketNumber = n; empty = false; }

Space::~Space()
{
}
std::string Space::getnoPlate() { if (!empty) { return noPlate; } else return ""; }
int Space::getticketNumber() {
	if (!empty)
	{
		return ticketNumber;
	}
	else return 0;
}
void Space::clear() { noPlate.clear(); ticketNumber = 0; empty = true; }
bool Space::getempty() { return empty; }