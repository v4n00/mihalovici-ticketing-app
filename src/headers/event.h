#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include "Room.h"
#include "Seat.h"

class Event {
private:
	std::string name = "";
	Date date;
	unsigned int runtime = 0;
	Room* room;

public:

};
