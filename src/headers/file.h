#pragma once
#include <fstream>
#include "../headers/ticket.h"

using std::fstream;

class File {
public:
	static char filename[];

	fstream fp;
	Location* locations = nullptr;
	int totalLocations = 0;

	void start();
	void firstTimeSetup();
	void loadData();
	void end();
};