#include <iostream>
#include <string>
#include "headers/seat.h"
#include "headers/room.h"
#include "headers/event.h"
#include "headers/date.h"
#include "headers/location.h"

using namespace std;

//TODO:
// today: 
// - implement addEvent method for location and addDate for event
// today++: implement ticket class

int main() {
	Date a(48, 6, 21, Month::AUGUST, 2022);
	Date b(28, 19, 19, Month::JULY, 2022);
	Room Projector1("Projector1", 1, 38, 4);
	Room Projector2("Projector2", 1, 48, 7);
	Event VE("Violet Evergarden", a, 88, Projector1);
	Event DN("Death Note", b, 85, Projector2);

	Event** events = new Event * [2];
	events[0] = &VE;
	events[1] = &DN;

	Location cinema("Cinema", "Str. dov 2", events, 2);
	cout << (string)cinema << endl;
	cout << *(cinema.getEvents()[1]);

	return 0;

}