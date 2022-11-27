#pragma once
#include <iostream>
#include <string>

enum class SeatAvailability {
	FREE,
	PAID,
	RESERVED
};

class Seat {
private:
	unsigned int seatId;
	SeatAvailability availability;
	static unsigned int TOTAL_SEATS;

	std::string enumToString(SeatAvailability availability);

public:

	void print();

	// - Getters/Setters

	int getSeatId();
	SeatAvailability getAvailability();

	void setAvailability(SeatAvailability newAvailability);

	// - Constructors/Destructors

	Seat(const Seat& anotherSeat);
	Seat(unsigned int seatId, SeatAvailability availability);
	Seat(unsigned int seatId);
	Seat();

	// - Stream operators

	friend std::ostream& operator << (std::ostream& out, const SeatAvailability availability);
	friend std::ostream& operator << (std::ostream& out, const Seat& seat);

	friend std::istream& operator >> (std::istream& in, SeatAvailability& availability);
	friend std::istream& operator >> (std::istream& in, Seat& seat);
};

