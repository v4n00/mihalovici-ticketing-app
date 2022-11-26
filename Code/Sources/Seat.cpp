#include "../Headers/Seat.h"

void Seat::print() {
	std::cout << "Seat #" << seatId << " is currently: " << (int)availability;
}

int Seat::getSeatId() {
	return this->seatId;
}

SeatAvailability Seat::getAvailability() {
	return this->availability;
}

void Seat::setAvailability(SeatAvailability newAvailability) {
	this->availability = newAvailability;
}

Seat::Seat() : seatId(++TOTAL_SEATS) {
	this->availability = SeatAvailability::FREE;
}