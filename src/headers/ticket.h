#pragma once
#include <stdlib.h>
#include <time.h>
#include "location.h"

class Ticket {
public:
	char* id;
	Event* event;
	Seat* seat;

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
	Ticket(Event& event, Seat& seat);
	Ticket();
	~Ticket();

};