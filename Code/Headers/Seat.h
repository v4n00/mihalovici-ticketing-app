#pragma once
#include <iostream>
#include <string>
#include <sstream>

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

	unsigned int seatId;
	SeatAvailability availability = SeatAvailability::FREE;

	static unsigned int TOTAL_SEATS;

	// Setters

	void setAvailability(SeatAvailability newAvailability);
	void setSeatId(unsigned int seatId);

public:


	// - Getters

	int getSeatId();
	SeatAvailability getAvailability();


	// - Constructors/Destructors

	Seat(const Seat& anotherSeat);
	Seat(unsigned int seatId, SeatAvailability availability);
	Seat(unsigned int seatId);
	Seat();

	// - Operators

		// copy assignment

	Seat operator=(const Seat& anotherSeat);

		// compare the seats

	bool operator==(const Seat& anotherSeat);
	bool operator!=(const Seat& anotherSeat);

		// print a verbose version of the seat

	explicit operator std::string();

		// stream operators

	friend std::ostream& operator << (std::ostream& out, const Seat& seat);
	friend std::istream& operator >> (std::istream& in, Seat& seat);

};

