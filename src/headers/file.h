#pragma once
#include <fstream>
#include <stdlib.h>
#include "../headers/ticket.h"

#ifdef _WIN32
#include <Windows.h>
#define Sleep(x) Sleep(x * 1000)
#else
#include <unistd.h>
#define system("CLS") system("clear")
#define Sleep(x) usleep(x * 1000000)
#endif

using std::fstream;

class File {
public:
	static char filename[];

	fstream fp;
	Location* locations = nullptr;
	int totalLocations = 0;
	Ticket* tickets = nullptr;
	int totalTickets = 0;

	void start();
	void firstTimeSetup();
	void loadData();
	void end();
};