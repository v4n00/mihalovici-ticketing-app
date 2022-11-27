#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include "Seat.h"
#include "Util.h"

class Room {
private:
	unsigned int roomId;
	char* name = nullptr;
	bool isVIP = false;
	Seat** seats = nullptr;
	unsigned int numberOfSeats = 0;

	static unsigned int TOTAL_ROOMS;
public:

	void seeRoomLayout();
	void addSeat();
	void changeSeat();
	static Seat** generateRoomOfSeats(unsigned int numberOfSeats);

	// - Getters/Setters

	char* getName();
	bool getVIPStatus();
	Seat** getSeats();
	int getNumberOfSeats();

	void setName(const char* name);
	void setType(const bool isVIP);
	void setSeats(Seat** anotherSeats, unsigned int numberOfSeats);

	// - Constructors / Destructors

	Room(const Room& anotherRoom);
	// make a room with n number of seats
	Room(const char* name, bool isVIP, unsigned int n);
	// make a room from an existing set of data
	Room(unsigned int roomId, const char* name, bool isVIP, Seat** seats, unsigned int numberOfSeats);
	// make an empty room
	Room();
	~Room();
	
	// - Operators

};