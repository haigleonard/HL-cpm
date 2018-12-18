#include "pch.h"
#include "Space.h"


//default constructor sets all spaces to empty string, ticketnumber 0 and empty
Space::Space() { 
	noplate = ""; 
	ticketnumber = 0; 
	empty = true; 
}

//Space constructor passing number palte and ticketnumber
Space::Space(std::string noplat, int ticketnum) { 
	noplate = noplat;
	ticketnumber = ticketnum;
	empty = false; 
}

Space::~Space()
{
}

//returns number plate, if empty is not true/filled
std::string Space::getnoPlate() { 
	if (!empty) return noplate;
	else return ""; 
}

//returns ticket number if empty is not true/filled
int Space::getticketNumber() {
	if (!empty) return ticketnumber;
	else return 0;
}

//sets space to empty (number plate to clear (""), tickernumber equalling 0 and empty to true)
void Space::clear() { 
	noplate.clear(); 
	ticketnumber = 0; 
	empty = true; 
}

//returns state of space
bool Space::getempty() { 
	return empty; 
}