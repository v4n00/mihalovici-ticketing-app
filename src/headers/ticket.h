#pragma once
#include <random>
#include "location.h"

class Ticket {
public:
	char* id = nullptr;
	Event* event = nullptr;
	unsigned int row = 0;
	unsigned int col = 0;

	static std::string VALID_TICKETS;
	static unsigned int TOTAL_TICKETS;

	// - Setters
	void setId(const char* id);
	void setEvent(Event& event);
	void setRow(unsigned int row);
	void setCol(unsigned int col);

	// - Private interface

	static char* generateId();

public:

	// - Public interface

	static bool isTicketValid(const char* id);
	void payForReservation();

	// - Getters

	static int getTotalTickets();
	char* getId() const;
	Event* getEvent() const;
	unsigned int getRow() const;
	unsigned int getCol() const;

	// - Constructors / Destructor

	Ticket(const Ticket& anotherTicket);
	// buys a ticket
	Ticket(Event* event, unsigned int row, unsigned int col, bool reserve);
	Ticket();
	// shouldnt delete anything as tickets and seats should remain
	~Ticket();


	// - Operators

		// copy assignment

	Ticket operator=(const Ticket& anotherTicket);

		// typecast operator

	explicit operator std::string();

		// stream operators

	friend std::ostream& operator << (std::ostream& out, const Ticket& ticket);
	friend std::istream& operator >> (std::istream& in, Ticket& ticket);
};