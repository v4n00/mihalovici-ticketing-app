#include <iostream>
#include <string>
#include "headers/seat.h"
#include "headers/room.h"
#include "headers/event.h"
#include "headers/date.h"

using namespace std;

//TODO:
// today: implement event class
// tmrw: implement ticket class
// tmrw++: implement location class

int main() {
	Date a(48, 6, 21, Month::AUGUST, 2022);
	cout << (string)a;
	return 0;

}