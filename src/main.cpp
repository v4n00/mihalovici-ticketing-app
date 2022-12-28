#include <iostream>
#include <fstream>
#include "headers/menu.h"

using namespace std;

// TODO:
// menu class
// exceptions

int main(int argc, char** argv) {
	Menu menu;
	menu.start(argc, argv);
	menu.end();
	return 0;
}