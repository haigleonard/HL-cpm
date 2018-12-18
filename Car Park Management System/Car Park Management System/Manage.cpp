#include "pch.h"
#include "Manage.h"


Manage::~Manage()
{
}

 bool Manage::processTicket()
{
	 /*
	 depending on first character of string, process each instruction accordingly 
	 and deduct each instruction with each iteration
	 contiue until string is either beginning with 'c', greater than 3 and 'p', or greater then 4 and 'u'
	 */
	 if (ticket == "") return false;
	while ((ticket.at(0) == 'c') || (ticket.size() > 3 && ticket.at(0) == 'p') || (ticket.size() > 4 && ticket.at(0) == 'u'))
	{
		// use ',' as delimianter
		char delimeter = ',';
		if (ticket.at(0) == 'p')
		{
			//substring being from 1 (character after 0) to next delimeter -1 (last character
			std::string reg = ticket.substr(1, ticket.find(delimeter) - 1);
			//add number plate
			carpark->addSpace(reg);
		}
		else if (ticket.at(0) == 'u')
		{
			// int value of the ticket to be removed
			int remove = stoi(ticket.substr(1, ticket.find(delimeter) - 1));
			//remove car
			carpark->removeSpace(remove);
		}
		else if (ticket.at(0) == 'c') 
			carpark->shuffle();
			
		//remove number plate from ticket, e.g from delimeter to the size (end) of string
		ticket = ticket.substr(ticket.find(delimeter) + 2, ticket.size());
		//if ticket length is 0, the while loop will break without this ammendment as ticket.at(0) is not possible
		if (ticket.size() == 0) { ticket = " "; }
	}
	return true;
}

 //print carpark
 void Manage::printCarPark() {
	 carpark->print();
 }
