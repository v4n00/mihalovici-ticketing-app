#include <iostream>
#include "headers/ticket.h"

using namespace std;

int main() {

	Room Projector1("Projector1", 1, 40, 4, 10);
	Room Projector2("Projector2", 1, 46, 7, 12);
	Location cinema("Cinema", "Str. dov 2");
	cinema.addEvent("Violet Evergarden", 87, Projector1, 30, 16, 27, Month::DECEMBER, 2022);
	cinema.addEvent("Death Note", 85, Projector2, 30, 16, 27, Month::DECEMBER, 2022);

	// display projector1

	Projector1.changeSeatAvailability(3, 4, SeatAvailability::PAID);
	Projector1.changeSeatAvailability(2, 1, SeatAvailability::RESERVED);
	Projector1.changeSeatAvailability(4, 7, SeatAvailability::PAID);

	cout << (string)Projector1 << endl;
	Projector1.printLayout(cout);
	cout << endl;

	// display projector2

	Projector2.changeSeatAvailability(3, 4, SeatAvailability::PAID);
	Projector2.changeSeatAvailability(2, 1, SeatAvailability::PAID);
	Projector2.changeSeatAvailability(3, 3, SeatAvailability::RESERVED);

	cout << (string)Projector2 << endl;
	Projector2.printLayout(cout);

	// display a location

	cout << endl << (string)cinema << endl;
	cout << "How it will be stored in a file: " << endl << endl << cinema << endl << endl;

	system("pause");

	return 0;
}