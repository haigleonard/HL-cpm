#include "pch.h"
#include "Manage.h"


Manage::~Manage()
{
}

 void Manage::processTicket()
{
	 /*
	 depending on first character of string, process each instruction accordingly 
	 and deduct each instruction with each iteration
	 contiue until string is either beginning with 'c', greater than 3 and 'p', or greater then 4 and 'u'
	 */
	while ((ticket.at(0) == 'c') || (ticket.size() > 3 && ticket.at(0) == 'p') || (ticket.size() > 4 && ticket.at(0) == 'u'))
	{
		char delimeter = ',';
		if (ticket.at(0) == 'p')
		{
			std::string reg = ticket.substr(1, ticket.find(delimeter) - 1);
			carpark->addSpace(reg);
			ticket = ticket.substr(ticket.find(delimeter) + 2, ticket.size());
		}
		else if (ticket.at(0) == 'u')
		{
			int remove = stoi(ticket.substr(1, ticket.find(delimeter)));
			carpark->removeSpace(remove);
			ticket = ticket.substr(ticket.find(delimeter) + 2, ticket.size());
		}
		else if (ticket.at(0) == 'c')
		{
			carpark->shuffle();
			ticket = ticket.substr(ticket.find(delimeter) + 2, ticket.size());
			if (ticket.size() == 0) { ticket = " "; }
		}
	}
	carpark->print();
	std::cout << std::endl;
}