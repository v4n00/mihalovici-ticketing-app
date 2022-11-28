#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include "Seat.h"
#include "Util.h"

//TODO:
// - function to see room layout, like a matrix on the console
// - function to change a seat availability relatively

class Room {
private:
	unsigned int roomId;
	char* name = nullptr;
	bool isVIP = false;
	unsigned int numberOfSeats = 0;
	unsigned int numberOfRows = 0;
	Seat** seats = nullptr;

	static unsigned int TOTAL_ROOMS;

	// - Setters

	void setRoomId(unsigned int roomId);
	void setName(const char* name);
	void setType(const bool isVIP);
	void setNumberOfSeats(unsigned int numberOfSeats);
	void setNumberOfRows(unsigned int numberOfRows);
	void setSeats(Seat** anotherSeats);

public:

	//void seeRoomLayout();
	void changeSeatAvailability(unsigned int seatId, SeatAvailability newAvailability);
	static Seat** generateRoomOfSeats(unsigned int numberOfSeats);

	// - Getters

	char* getName();
	bool getVIPStatus();
	Seat** getSeats();
	unsigned int getNumberOfSeats();
	unsigned int getNumberOfRows();


	// - Constructors / Destructors

	Room(const Room& anotherRoom);
	// make a room with n number of seats
	Room(const char* name, bool isVIP, unsigned int n);
	// make a room from an existing set of data
	Room(unsigned int roomId, const char* name, bool isVIP, Seat** seats, unsigned int numberOfSeats, unsigned int numberOfRows);
	// make an empty room
	Room();
	~Room();
	
	// - Operators

		// cast operator
	
	explicit operator std::string();

		// compare the rooms

	bool operator==(const Room& anotherRoom);
	bool operator!=(const Room& anotherRoom);

		// stream operators

	friend std::ostream& operator << (std::ostream& out, const Room& room);
	friend std::istream& operator >> (std::istream& in, Room& room);
};