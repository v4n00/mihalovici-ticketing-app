#pragma once

enum class SeatAvailability {
	FREE,
	PAID,
	RESERVED
};

class Seat {
private:
	const unsigned int seatId;
	SeatAvailability availability;

	int generateId();

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