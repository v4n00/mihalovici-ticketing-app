#pragma once
#include <stdlib.h>
#include <time.h>
#include "location.h"

// I cannot make this class without an STL class so I'm gonna stop here

class Ticket {
public:
	char* ticketId;
	Event* event;

	static unsigned int* VALID_TICKETS;
	static unsigned int NO_VALID_TICKETS;

	// - Setter
	void setEvent(Event* event);
	void setTicketId(unsigned int ticketId);

	// - Private interface

	static char* generateId();

public:

	// - Getter
	unsigned int getTicketId();
	Event* getEvent();

	// - Constructors / Destructor
	Ticket();
	~Ticket();

};