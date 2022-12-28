#pragma once
#include <fstream>
#include "../headers/ticket.h"

using std::fstream;

class File {
public:
	static void start();
	static void firstTimeSetup(std::fstream& fp);
};