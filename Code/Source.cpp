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
	Room a("Cinema", 1, 56, 7);
	a.changeSeatAvailability(1, 1, SeatAvailability::PAID);
	a.changeSeatAvailability(1, 2, SeatAvailability::PAID);
	a.changeSeatAvailability(3, 3, SeatAvailability::PAID);
	a.changeSeatAvailability(7, 8, SeatAvailability::PAID);
	a.printLayout();
	return 0;
}