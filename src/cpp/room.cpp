#include "../headers/room.h"

unsigned int Room::TOTAL_ROOMS = 0;

// - Setters

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

void Room::setPricePerSeat(unsigned int pricePerSeat) {
	if (pricePerSeat > 0)
		this->pricePerSeat = pricePerSeat;
	else throw;
}

// - Public interface

void Room::setAllSeatsToFree() {
	for (size_t i = 0; i < numberOfSeats; ++i) {
		this->seats[i]->setAvailability(SeatAvailability::FREE);
	}
}

void Room::printLayout(std::ostream& out) {
	size_t i, j, totalSeats, numberOfColumns;

	// 17 seats / 3 rows => 6 columns
	// 15 seats / 3 rows => 5 columns
	numberOfColumns = getNumberOfColumns();
	totalSeats = numberOfSeats;

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
	bool ok = 0;
	for (size_t i = 0; i < this->numberOfSeats && ok == 0; ++i)
		if (this->seats[i]->getId() == seatId) {
			this->seats[i]->setAvailability(newAvailability);
			ok = 1;
		}
}

void Room::checkSeatOverlap(unsigned int row, unsigned int col, SeatAvailability availability) {
	int seatIdA = getRelativeSeatId(row, col);
	for (size_t i = 0; i < this->numberOfSeats; ++i) {
		if (this->seats[i]->id == seatIdA && this->seats[i]->availability == availability)
			throw;
	}
}

void Room::changeSeatAvailability(unsigned int row, unsigned int col, SeatAvailability newAvailability) {
	this->checkSeatOverlap(row, col, newAvailability);
	this->changeSeatAvailability(getRelativeSeatId(row, col), newAvailability);
}

int Room::getRelativeSeatId(unsigned int row, unsigned int col) {
	// this unironically took me 1 hour to figure out, DO NOT TOUCH
	// row 3 col 3 => seat 19
	// row 2 col 4 => seat 12
	// if we have some seats missing from the front this is suppoed to fix that
	int factorDeCorectie1 = (numberOfSeats % numberOfRows == 0) ? 0 : (numberOfRows - (numberOfSeats % numberOfRows));
	// method changes the availability based on a relative Seat from all the seats ever created
	int factorDeCorectie2 = seats[0]->getId() - 1 - factorDeCorectie1;
	int rez = (row * col) + (row - 1) * (getNumberOfColumns() - col) + factorDeCorectie2;
	return rez;
}

Seat Room::getRelativeSeat(unsigned int row, unsigned int col) {
	int seatIdA = getRelativeSeatId(row, col);
	for (size_t i = 0; i < this->numberOfSeats; ++i) {
		if (this->seats[i]->id == seatIdA)
			return *this->seats[i];
	}
}

Seat** Room::generateRoomOfSeats(unsigned int numberOfSeats) {
	Seat** rez = new Seat * [numberOfSeats];
	for (size_t i = 0; i < numberOfSeats; ++i)
		rez[i] = new Seat();
	return rez;
}

// - Getters

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

unsigned int Room::getNumberOfColumns() {
	return numberOfSeats % numberOfRows == 0 ? numberOfSeats / numberOfRows : (size_t)(numberOfSeats / numberOfRows) + 1;
}

unsigned int Room::getPricePerSeat() {
	return this->pricePerSeat;
}

// - Constructors / Destructor

Room::Room(const Room& anotherRoom) {
	this->setId(anotherRoom.id);
	this->setName(anotherRoom.name);
	this->setType(anotherRoom.isVIP);
	this->setNumberOfSeats(anotherRoom.numberOfSeats);
	this->setSeats(anotherRoom.seats);
	this->setNumberOfRows(anotherRoom.numberOfRows);
	this->setPricePerSeat(anotherRoom.pricePerSeat);
	++TOTAL_ROOMS;
}

Room::Room(const char* name, bool isVIP, unsigned int n, unsigned int numberOfRows, unsigned int pricePerSeat) {
	this->setId(++TOTAL_ROOMS);
	this->setName(name);
	this->setType(isVIP);
	this->setNumberOfSeats(n);
	this->setNumberOfRows(numberOfRows);
	this->setPricePerSeat(pricePerSeat);
	this->seats = Room::generateRoomOfSeats(n);
}

Room::Room() {
	this->setId(++TOTAL_ROOMS);
}

Room::~Room() {
	delete[] name;
	for (size_t i = 0; i < this->numberOfSeats; ++i)
		delete seats[i];
	delete[] seats;
	--TOTAL_ROOMS;
}

// - Operators

// copy assignemnt

Room Room::operator=(const Room& anotherRoom) {
	this->setId(anotherRoom.id);
	this->setName(anotherRoom.name);
	this->setType(anotherRoom.isVIP);
	this->setNumberOfSeats(anotherRoom.numberOfSeats);
	this->setSeats(anotherRoom.seats);
	this->setNumberOfRows(anotherRoom.numberOfRows);
	this->setPricePerSeat(anotherRoom.pricePerSeat);
	return *this;
}

// typecast operator

Room::operator std::string() {
	std::stringstream ss;
	std::string isVIP = this->isVIP ? "VIP" : "not VIP";
	ss << "Room #" << id << " named \"" << name << "\"" << ", " << isVIP << ", which has "
		<< numberOfRows << " rows and " << numberOfSeats << " seats with a price of " << pricePerSeat << " RON per seat";
	return ss.str();
}

// compare operator

bool Room::operator==(const Room& anotherRoom) {
	if (this == &anotherRoom)
		return true;
	if (id != anotherRoom.id)
		return false;
	if (strcmp(name, anotherRoom.name) != 0)
		return false;
	if (isVIP != anotherRoom.isVIP)
		return false;
	if (numberOfSeats != anotherRoom.numberOfSeats)
		return false;
	if (numberOfRows != anotherRoom.numberOfRows)
		return false;
	if (pricePerSeat != anotherRoom.pricePerSeat)
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
	out << "R" << room.id << "-" << room.name << "-" << room.isVIP << "-" << room.numberOfRows << "-" << room.pricePerSeat << "-" << room.numberOfSeats << ":";
	for (size_t i = 0; i < room.numberOfSeats; ++i)
		out << *(room.seats[i]);
	out << ";";
	return out;
}

std::istream& operator >> (std::istream& in, Room& room) {
	// inspired from https://stackoverflow.com/questions/22290891/reading-in-file-with-delimiter
	std::string id;
	std::string name;
	std::string isVIP;
	std::string numberOfSeats;
	std::string numberOfRows;
	std::string pricePerSeat;
	if (std::getline(in, id, 'R') &&
		std::getline(in, id, '-') &&
		std::getline(in, name, '-') &&
		std::getline(in, isVIP, '-') &&
		std::getline(in, numberOfRows, '-') &&
		std::getline(in, pricePerSeat, '-') &&
		std::getline(in, numberOfSeats, ':')) {
			room.setId(std::stoi(id));
			room.setName(name.c_str());
			room.setType(std::stoi(isVIP));
			room.setNumberOfSeats(std::stoi(numberOfSeats));
			room.setNumberOfRows(std::stoi(numberOfRows));
			room.setPricePerSeat(std::stoi(pricePerSeat));
	}
	else throw;
	room.seats = new Seat * [room.numberOfSeats];
	for (size_t i = 0; i < room.numberOfSeats; ++i) {
		room.seats[i] = new Seat();
		if (!(in >> *(room.seats[i])))
			throw;
	}
	getline(in, id, ';');
	return in;
}