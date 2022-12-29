#include <iostream>
#include <fstream>
#include "headers/menu.h"

using namespace std;

int main(int argc, char** argv) {
	try {
		Menu menu;
		menu.start(argc, argv);
		menu.end();
	}
	catch (exception e) {
		cout << "Error: " << e.what();
	}
	return 0;
}