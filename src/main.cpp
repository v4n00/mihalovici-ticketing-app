#include <iostream>
#include <string>
#include "headers/seat.h"
#include "headers/room.h"
#include "headers/event.h"
#include "headers/date.h"

using namespace std;

//TODO:
// today: implement event class
// today: implement ticket class
// today++: implement location class

int main() {
	Date a(48, 6, 21, Month::AUGUST, 2022);
	Room b("Projector", 1, 2, 1);
	Event c("Violet Evergarden", a, 98, b);

	cout << c << endl << endl;

	Event d;
	cin >> d;
	cout << (string)d;
	return 0;

}