#include "../Headers/Room.h"

unsigned int Room::TOTAL_ROOMS = 0;

// - Setters

void Room::setRoomId(unsigned int roomId) {
	if (roomId != 0)
		this->roomId = roomId;
	else throw;
}

void Room::setName(const char* name) {
	if (strlen(name) != 1)
		this->name = Util::deepCopy(name);
	else throw;
}

void Room::setType(const bool isVIP) {
	this->isVIP = isVIP;
}

void Room::setNumberOfSeats(unsigned int numberOfSeats) {
	if (numberOfSeats != 0)
		this->numberOfSeats = numberOfSeats;
	else throw;
}

void Room::setSeats(Seat** seats) {
	if (seats != nullptr) {
		this->seats = new Seat * [numberOfSeats];
		for (size_t i = 0; i < numberOfSeats; ++i)
			this->seats[i] = new Seat(*(seats[i]));
	}
	else throw;
}

void Room::setNumberOfRows(unsigned int numberOfRows) {
	if (numberOfRows < this->numberOfSeats)
		this->numberOfRows = numberOfRows;
	else throw;
}

unsigned int Room::getNumberOfColumns() {
	return numberOfSeats % numberOfRows == 0 ? numberOfSeats / numberOfRows : (size_t)(numberOfSeats / numberOfRows) + 1;
}

// - Public interface

void Room::printLayout(std::ostream& out) {
	size_t i, j, totalSeats, numberOfColumns;

	std::string isVIP = this->isVIP ? "VIP" : "not VIP";
	// 17 seats / 3 rows => 6 columns
	// 15 seats / 3 rows => 5 columns
	numberOfColumns = getNumberOfColumns();
	totalSeats = numberOfSeats;

	out << "Room #" << roomId << " named \"" << name << "\"" << " is " << isVIP << ", has "
		<< numberOfRows << " rows and " << numberOfSeats << " seats:\n\n";

	out << "R\\C ";
	for (j = numberOfColumns; j > 0; --j)
		out << std::setw(3) << j << " ";
	out << std::endl;
	for (i = numberOfRows; i > 0; --i) {
		out << std::setw(2) << std::right << i << " ";
		for (j = numberOfColumns; j > 0 && totalSeats > 0; --j) {
			totalSeats--;
			out << std::setw(4) << std::right << seats[totalSeats]->getAvailabilityAsSymbol();
		}
		out << std::endl;
	}

	out << std::endl << std::setw(5) << " ";
	for (j = numberOfColumns * 4 - 1; j > 0; --j)
		out << "x";
	out << "  <- the event" << std::endl;
}

void Room::changeSeatAvailability(unsigned int seatId, SeatAvailability newAvailability) {
	for (size_t i = 0; i < this->numberOfSeats; ++i)
		if (this->seats[i]->getSeatId() == seatId)
			this->seats[i]->setAvailability(newAvailability);
}

void Room::changeSeatAvailability(unsigned int row, unsigned int col, SeatAvailability newAvailability) {
	// row 3 col 3 => seat 19
	// row 2 col 4 => seat 12
	// this unironically took me 1 hour to figure out
	this->changeSeatAvailability(row*col + (row-1) * (getNumberOfColumns() - col) + seats[0]->getSeatId() - 1, newAvailability);
}

Seat** Room::generateRoomOfSeats(unsigned int numberOfSeats) {
	Seat** rez = new Seat * [numberOfSeats];
	for (size_t i = 0; i < numberOfSeats; ++i)
		rez[i] = new Seat();
	return rez;
}

// - Getters

char* Room::getName() {
	return Util::deepCopy(this->name);
}

bool Room::getIsVIP() {
	return this->isVIP;
}

Seat** Room::getSeats() {
	Seat** rez = new Seat * [numberOfSeats];
	for (size_t i = 0; i < numberOfSeats; ++i)
		rez[i] = new Seat(*(this->seats[i]));
	return rez;
}

unsigned int Room::getNumberOfSeats() {
	return this->numberOfSeats;
}

unsigned int Room::getNumberOfRows() {
	return this->numberOfRows;
}

// - Constructors / Destructor

Room::Room(const Room& anotherRoom) {
	this->setRoomId(anotherRoom.roomId);
	this->setName(anotherRoom.name);
	this->setType(anotherRoom.isVIP);
	this->setNumberOfSeats(anotherRoom.numberOfSeats);
	this->setSeats(anotherRoom.seats);
	this->setNumberOfRows(anotherRoom.numberOfRows);
	TOTAL_ROOMS++;
}

Room::Room(const char* name, bool isVIP, unsigned int n, unsigned int numberOfRows) {
	this->setRoomId(++TOTAL_ROOMS);
	this->setName(name);
	this->setType(isVIP);
	this->setNumberOfSeats(n);
	this->setNumberOfRows(numberOfRows);
	this->seats = Room::generateRoomOfSeats(n);
}

Room::Room(unsigned int roomId, const char* name, bool isVIP, Seat** seats, unsigned int numberOfSeats, unsigned int numberOfRows) {
	this->setRoomId(roomId);
	this->setName(name);
	this->setType(isVIP);
	this->setNumberOfSeats(numberOfSeats);
	this->setSeats(seats);
	this->setNumberOfRows(numberOfRows);
	TOTAL_ROOMS++;
}

Room::Room() {
	this->setRoomId(++TOTAL_ROOMS);
}

Room::~Room() {
	delete[] name;
	for (size_t i = 0; i < this->numberOfSeats; ++i)
		delete seats[i];
	delete[] seats;
}

// - Operators

// copy assignemnt

Room Room::operator=(const Room& anotherRoom) {
	this->setRoomId(anotherRoom.roomId);
	this->setName(anotherRoom.name);
	this->setType(anotherRoom.isVIP);
	this->setNumberOfSeats(anotherRoom.numberOfSeats);
	this->setSeats(anotherRoom.seats);
	this->setNumberOfRows(anotherRoom.numberOfRows);
	return *this;
}

// typecast operator

Room::operator std::string() {
	std::stringstream ss;
	std::string isVIP = this->isVIP ? "VIP" : "not VIP";
	ss << "Room #" << roomId << " named \"" << name << "\"" << " is " << isVIP << ", has "
		<< numberOfRows << " rows and " << numberOfSeats << " seats:" << std::endl;
	for (size_t i = 0; i < numberOfSeats; ++i)
		ss << (std::string) * (this->seats[i]) << std::endl;
	return ss.str();
}

// compare operator

bool Room::operator==(const Room& anotherRoom) {
	if (this == &anotherRoom)
		return true;
	if (roomId != anotherRoom.roomId)
		return false;
	if (strcmp(name, anotherRoom.name) != 0)
		return false;
	if (isVIP != anotherRoom.isVIP)
		return false;
	if (numberOfSeats != anotherRoom.numberOfSeats)
		return false;
	if (numberOfRows != anotherRoom.numberOfRows)
		return false;
	for (size_t i = 0; i < numberOfSeats; ++i)
		if (seats[i] != anotherRoom.seats[i])
			return false;
	return true;
}

bool Room::operator!=(const Room& anotherRoom) {
	return !(*this == anotherRoom);
}

// stream operators

std::ostream& operator << (std::ostream& out, const Room& room) {
	out << "R" << room.roomId << "-" << room.name << "-" << room.isVIP << "-" << room.numberOfRows << "-" << room.numberOfSeats << ":";
	for (size_t i = 0; i < room.numberOfSeats; ++i)
		out << *(room.seats[i]);
	out << ";";
	return out;
}

std::istream& operator >> (std::istream& in, Room& room) {
	// inspired from https://stackoverflow.com/questions/22290891/reading-in-file-with-delimiter
	std::string roomId;
	std::string name;
	std::string isVIP;
	std::string numberOfSeats;
	std::string numberOfRows;
	if (std::getline(in, roomId, 'R') &&
		std::getline(in, roomId, '-') &&
		std::getline(in, name, '-') &&
		std::getline(in, isVIP, '-') &&
		std::getline(in, numberOfRows, '-') &&
		std::getline(in, numberOfSeats, ':')) {
			room.setRoomId(std::stoi(roomId));
			/*room.name = new char[name.length() + 1];
			strcpy_s(room.name, name.length() + 1, name.c_str());*/
			room.setName(name.c_str());
			room.setType(std::stoi(isVIP));
			room.setNumberOfSeats(std::stoi(numberOfSeats));
			room.setNumberOfRows(std::stoi(numberOfRows));
	}
	room.seats = new Seat * [room.numberOfSeats];
	for (size_t i = 0; i < room.numberOfSeats; ++i) {
		room.seats[i] = new Seat();
		in >> *(room.seats[i]);
	}
	getline(in, roomId, ';');
	return in;
}