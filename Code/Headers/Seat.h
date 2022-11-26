#pragma once
#include <iostream>

enum class SeatAvailability {
	FREE,
	PAID,
	RESERVED
};

class Seat {
private:
	const unsigned int seatId;
	SeatAvailability availability;
	static unsigned int TOTAL_SEATS;

public:

	void print();

	// - Getters/Setters

	int getSeatId();
	SeatAvailability getAvailability();

	void setAvailability(SeatAvailability newAvailability);

	// - Constructors/Destructors

	Seat(const Seat& anotherSeat);
	Seat();
};

unsigned int Seat::TOTAL_SEATS = 0;