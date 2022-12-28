#pragma once
#include <iostream>
#include "file.h"

using std::cout;
using std::cin;
using std::endl;

class Menu {
public:
	File file;

	void start(int argc, char** argv);
	void end();

	int node0(int choice);

	void option1();
	int option11(int choice1);
	int option12(int choice2, Location& location);
	void option2();
	void option3();
};