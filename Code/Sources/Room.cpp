#include "../Headers/Room.h"

unsigned int Room::TOTAL_ROOMS = 0;

Seat** Room::generateRoomOfSeats(unsigned int numberOfSeats) {
	Seat** rez = new Seat * [numberOfSeats];
	for (size_t i = 0; i < numberOfSeats; ++i)
		rez[i] = new Seat();
	return rez;
}

// - Getters/Setters
char* Room::getName() {
	return Util::deepCopy(this->name);
}

bool Room::getVIPStatus() {
	return this->isVIP;
}

Seat** Room::getSeats() {
	Seat** rez = new Seat * [numberOfSeats];
	for (size_t i = 0; i < numberOfSeats; ++i)
		rez[i] = new Seat(*(this->seats[i]));
	return rez;
}

int Room::getNumberOfSeats() {
	return this->numberOfSeats;
}

void Room::setName(const char* name) {
	this->name = Util::deepCopy(name);
}

void Room::setType(const bool isVIP) {
	this->isVIP = isVIP;
}

void Room::setSeats(Seat** seats, unsigned int numberOfSeats) {
	if (numberOfSeats != 0 && seats != nullptr) {
		this->numberOfSeats = numberOfSeats;
		this->seats = new Seat * [numberOfSeats];
		for (size_t i = 0; i < numberOfSeats; ++i)
			this->seats[i] = new Seat(*(seats[i]));
	}
	else throw;
}

// - Constructors / Destructors

Room::Room(const Room& anotherRoom) {
	this->roomId = anotherRoom.roomId;
	TOTAL_ROOMS++;
	this->setName(anotherRoom.name);
	this->setType(anotherRoom.isVIP);
	this->setSeats(anotherRoom.seats, anotherRoom.numberOfSeats);
}

Room::Room(const char* name, bool isVIP, unsigned int n) {
	this->roomId = roomId;
	TOTAL_ROOMS++;
	this->setName(name);
	this->isVIP = isVIP;
	this->numberOfSeats = n;
	this->seats = Room::generateRoomOfSeats(n);
}

Room::Room(unsigned int roomId, const char* name, bool isVIP, Seat** seats, unsigned int numberOfSeats) {
	this->roomId = roomId;
	TOTAL_ROOMS++;
	this->setName(name);
	this->setType(isVIP);
	this->setSeats(seats, numberOfSeats);
}

Room::Room() {
	this->roomId = ++TOTAL_ROOMS;
}

Room::~Room() {
	delete[] name;
	for (size_t i = 0; i < this->numberOfSeats; ++i)
		delete seats[i];
	delete[] seats;
}