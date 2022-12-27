#include "../headers/ticket.h"

std::string Ticket::VALID_TICKETS = "";
unsigned int Ticket::TOTAL_TICKETS = 0;

// - Setters

void Ticket::setId(const char* id) {
	if (id != nullptr && strlen(id) == 8)
		this->id = Entity::deepCopy(id, strlen(id) + 1);
	else throw;
}

void Ticket::setEvent(Event& event) {
	if (&event != nullptr)
		this->event = &event;
	else throw;
}

void Ticket::setRow(unsigned int row) {
	if (row > 0 && row <= this->event->getRoom()->getNumberOfRows())
		this->row = row;
	else throw;
}

void Ticket::setCol(unsigned int col) {
	if (col > 0 && col <= this->event->getRoom()->getNumberOfColumns())
		this->col = col;
	else throw;
}

// - Private interface

char* Ticket::generateId() {
	char* id = new char[9];
	char hex[16] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
	// got this from https://stackoverflow.com/questions/19665818/generate-random-numbers-using-c11-random-library
	// because rand() wasnt doing random numbers
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, 15);
	for (int i = 0; i < 8; ++i) {
		id[i] = hex[dist(mt)];
	}
	id[8] = '\0';
	return id;
}

// - Public interface

bool Ticket::isTicketValid(const char* id) {
	if (VALID_TICKETS.find(id) == std::string::npos)
		return 0;
	return 1;
}

void Ticket::payForReservation() {
	this->event->room->changeSeatAvailability(row, col, SeatAvailability::PAID);
}

// - Getters

char* Ticket::getId() const {
	return Entity::deepCopy(id, strlen(id) + 1);
}

Event* Ticket::getEvent() const {
	return event;
}

unsigned int Ticket::getRow() const {
	return row;
}

unsigned int Ticket::getCol() const {
	return col;
}

// - Constructor

Ticket::Ticket(Event* event, unsigned int row, unsigned int col, bool reserve) {
	this->setId(generateId());
	this->setEvent(*event);
	if(reserve = 0)
		this->event->room->changeSeatAvailability(row, col, SeatAvailability::RESERVED);
	else
		this->event->room->changeSeatAvailability(row, col, SeatAvailability::PAID);
	VALID_TICKETS += id;
	++TOTAL_TICKETS;
}

Ticket::Ticket() {
	++TOTAL_TICKETS;
}

Ticket::~Ticket() {
	delete[] id;
	--TOTAL_TICKETS;
}