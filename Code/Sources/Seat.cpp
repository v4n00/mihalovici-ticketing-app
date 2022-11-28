#include "../Headers/Seat.h"

unsigned int Seat::TOTAL_SEATS = 0;

// - SeatAvailability operators

std::ostream& operator << (std::ostream& out, const SeatAvailability& availability) {
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

// - Getters/Setters

int Seat::getSeatId() {
	return this->seatId;
}

SeatAvailability Seat::getAvailability() {
	return this->availability;
}

void Seat::setAvailability(SeatAvailability newAvailability) {
	if ((int)newAvailability > 2 || (int)newAvailability < 0)
		this->availability = SeatAvailability::FREE;
	else
		this->availability = newAvailability;
}

// - Constructors/Destructors

Seat::Seat(const Seat& anotherSeat) {
	this->seatId = anotherSeat.seatId;
	this->availability = anotherSeat.availability;
	++TOTAL_SEATS;
}

Seat::Seat(unsigned int seatId, SeatAvailability availability) {
	this->seatId = seatId;
	this->setAvailability(availability);
	++TOTAL_SEATS;
}

Seat::Seat(unsigned int seatId) {
	this->seatId = seatId;
	++TOTAL_SEATS;
}

Seat::Seat() {
	this->seatId = ++TOTAL_SEATS;
}

// - Operators

Seat Seat::operator=(const Seat& anotherSeat) {
	this->seatId = anotherSeat.seatId;
	this->availability = anotherSeat.availability;
	return *this;
}

Seat Seat::operator++() {
	this->availability = SeatAvailability::PAID;
	return *this;
}

Seat Seat::operator++(int) {
	Seat temp(*this);
	operator++();
	return temp;
}

Seat Seat::operator--() {
	this->availability = SeatAvailability::FREE;
	return *this;
}

Seat Seat::operator--(int) {
	Seat temp(*this);
	operator--();
	return temp;
}

bool Seat::operator==(const Seat& anotherSeat) {
	if (this == &anotherSeat)
		return true;
	if (this->seatId == anotherSeat.seatId)
		return false;
	if (this->availability == anotherSeat.availability)
		return false;
	return true;
}

bool Seat::operator!=(const Seat& anotherSeat) {
	return !(*this == anotherSeat);
}

Seat::operator std::string() {
	std::stringstream ss;
	ss << "Seat #" << this->seatId << " is currently: " << this->availability;
	return ss.str();
}

// - Stream operators

std::ostream& operator << (std::ostream& out, const Seat& seat) {
	out << "S" << seat.seatId << "-" << (int)seat.availability << ":";
	return out;
}

std::istream& operator >> (std::istream& in, Seat& seat) {
	// inspired from https://stackoverflow.com/questions/22290891/reading-in-file-with-delimiter
	std::string seatId;
	std::string availability;
	if (std::getline(in, seatId, 'S') &&
		std::getline(in, seatId, '-') &&
		std::getline(in, availability, ':')) {
			seat.seatId = std::stoi(seatId);
			seat.availability = (SeatAvailability) std::stoi(availability);
	}
	return in;
}