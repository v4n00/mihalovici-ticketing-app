#include "../Headers/Seat.h"

unsigned int Seat::TOTAL_SEATS = 0;

// - Getters/Setters

int Seat::getSeatId() {
	return this->seatId;
}

SeatAvailability Seat::getAvailability() {
	return this->availability;
}

void Seat::setAvailability(SeatAvailability newAvailability) {
	this->availability = newAvailability;
}

// - Constructors/Destructors

Seat::Seat(unsigned int seatId, SeatAvailability availability) : seatId(seatId) {
	this->availability = availability;
}

Seat::Seat(unsigned int seatId) : seatId(seatId) {
	this->availability = SeatAvailability::FREE;
}

Seat::Seat() : seatId(++TOTAL_SEATS) {
	this->availability = SeatAvailability::FREE;
}

// - Stream operators

std::ostream& operator << (std::ostream& out, const SeatAvailability availability) {
	switch (availability) {
	case SeatAvailability::FREE:
		out << "free"; break;
	case SeatAvailability::RESERVED:
		out << "reserved"; break;
	case SeatAvailability::PAID:
		out << "paid"; break;
	default:
		out << "unknown";
	}
	return out;
}

std::ostream& operator << (std::ostream& out, const Seat& seat) {
	out << "Seat #" << seat.seatId << " is currently: " << seat.availability;
	return out;
}

std::istream& operator >> (std::istream& in, SeatAvailability& availability) {
	int i = 0;
	if (!(in >> i) || i > 2) {
		availability = (SeatAvailability)0;
		return in;
	}
	else
		availability = (SeatAvailability)i;
	return in;
}

std::istream& operator >> (std::istream& in, Seat& seat) {
	std::cout << "Insert seatId: ";
	in >> seat.seatId;
	std::cout << "Insert availability: ";
	in >> seat.availability;
	return in;
}
