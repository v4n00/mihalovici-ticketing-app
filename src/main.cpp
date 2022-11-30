#include <iostream>
#include <string>
#include "headers/location.h"

using namespace std;

//TODO:
// today++: implement ticket class
// (today++)++: implement menu class

int main() {

	Room Projector1("Projector1", 1, 38, 4);
	Room Projector2("Projector2", 1, 48, 7);
	Location cinema("Cinema", "Str. dov 2");
	cinema.addEvent("Violet Evergarden", 87, Projector1, 30, 16, 27, Month::DECEMBER, 2022);
	cinema.addEvent("Death Note", 85, Projector2, 30, 16, 27, Month::DECEMBER, 2022);
	cinema.getEvents()[0]->getRoom()->printLayout();
	cinema.getEvents()[1]->getRoom()->printLayout();
	cout << (string)cinema;

	return 0;

}