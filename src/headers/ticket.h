#pragma once
#include <stdlib.h>
#include <vector>
#include "location.h"

class Ticket {
private:
	char* id = nullptr;
	Event* event = nullptr;
	unsigned int row = 0;
	unsigned int col = 0;

	//static std::vector<char*> VALID_TICKETS;
	static unsigned int TOTAL_TICKETS;

	// - Setters
	void setId(const char* id);
	void setEvent(Event& event);
	void setRow(unsigned int row);
	void setCol(unsigned int col);

	// - Private interface

	static char* generateId();

public:

	// - Getters

	char* getId() const;
	Event* getEvent() const;
	unsigned int getRow() const;
	unsigned int getCol() const;

	// - Constructors / Destructor

	// buys a ticket
	Ticket(Event* event, unsigned int row, unsigned int col, bool reserve);
	Ticket();
	// shouldnt delete anything as tickets and seats should remain
	~Ticket();

};