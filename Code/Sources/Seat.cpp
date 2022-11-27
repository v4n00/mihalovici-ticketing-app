#include "../Headers/Seat.h"

unsigned int Seat::TOTAL_SEATS = 0;

void Seat::print() {
	std::cout << "Seat #" << seatId << " is currently: " << enumToString(this->availability);
}

std::string Seat::enumToString(SeatAvailability availability) {
	switch (availability) {
	case SeatAvailability::FREE: return "free"; break;
	case SeatAvailability::RESERVED: return "reserved"; break;
	case SeatAvailability::PAID: return "paid"; break;
	default: return "unknown";
	}
}

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

std::ostream& operator << (std::ostream& out, const Seat& c) {
	out << 
}