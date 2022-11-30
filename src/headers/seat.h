#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "util.h"

enum class SeatAvailability {
	FREE,
	PAID,
	RESERVED
};

// - SeatAvailability operators

std::ostream& operator << (std::ostream& out, const SeatAvailability& availability);
std::istream& operator >> (std::istream& in, SeatAvailability& availability);

class Seat {
private:

	friend class Room;

	unsigned int seatId = 0;
	SeatAvailability availability = SeatAvailability::FREE;

	static unsigned int TOTAL_SEATS;

	// - Setters

	void setAvailability(SeatAvailability newAvailability);
	void setSeatId(unsigned int seatId);

public:

	// - Public Interface

	char getAvailabilityAsSymbol();

	// - Getters

	int getSeatId();
	SeatAvailability getAvailability();

	// - Constructors

	// copy constructor
	Seat(const Seat& anotherSeat);
	// make an empty seat
	Seat();
	~Seat();

	// - Operators

		// copy assignment

	Seat operator=(const Seat& anotherSeat);

		// compare operators

	bool operator==(const Seat& anotherSeat);
	bool operator!=(const Seat& anotherSeat);

		// string typecast, print a verbose Seat for whatever reason you might find suited

	explicit operator std::string();

		// stream operators

	friend std::ostream& operator << (std::ostream& out, const Seat& seat);
	friend std::istream& operator >> (std::istream& in, Seat& seat);

};

