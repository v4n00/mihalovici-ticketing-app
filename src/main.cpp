#include <iostream>
#include <fstream>
#include "headers/menu.h"

using namespace std;

int main(int argc, char** argv) {
	Menu menu;
	menu.start(argc, argv);
	menu.end();
	return 0;
}