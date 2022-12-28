#include <iostream>
#include <fstream>
#include "headers/menu.h"

using namespace std;

// TODO:
// menu class
// exceptions

int main(int argc, char** argv) {
	/*File file;
	file.start(argc, argv);
	cout << (string)*(file.locations[0].getEvents()[0]) << endl << endl;
	file.locations[0].getEvents()[0]->getRoom()->printLayout();
	cout << file.tickets[0];
	file.end();*/



	Menu menu;
	menu.start(argc, argv);
	menu.end();

	return 0;
}