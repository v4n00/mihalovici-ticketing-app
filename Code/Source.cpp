#include <iostream>
#include <string>
#include "Headers/Seat.h"
#include "Headers/Room.h"

using namespace std;

//TODO:
// Room - function to change a seat availability relatively
// implement event class
// implement ticket class

int main() {
	Room a("Cinema", 1, 17, 3);
	a.changeSeatAvailability(13, SeatAvailability::PAID);
	a.changeSeatAvailability(10, SeatAvailability::PAID);
	a.changeSeatAvailability(3, SeatAvailability::PAID);
	a.changeSeatAvailability(4, SeatAvailability::RESERVED);
	a.printRoomLayout();
	return 0;
}