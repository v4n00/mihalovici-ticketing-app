#include <iostream>
#include <fstream>
#include "headers/file.h"

using namespace std;

int main() {
	File file;
	file.start();
	cout << (string)*(file.locations[0].getEvents()[0]) << endl << endl;
	file.locations[0].getEvents()[0]->getRoom()->printLayout();
	Ticket a(file.locations[0].getEvents()[0], 2, 2, 1);
	file.locations[0].getEvents()[0]->getRoom()->printLayout();
	file.end();
	return 0;
}