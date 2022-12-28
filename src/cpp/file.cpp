#include "../headers/file.h"

char File::filename[] = "Data.dat";

void File::start() {
	fp.open(File::filename, fstream::in);

	// if file doesnt exist, make it
	if (!fp.is_open()) {
		std::cout << "!!! First Time setup, creating files..." << std::endl;
		Sleep(1);
		fp.open(filename, fstream::out);

		firstTimeSetup();
	}
	// if file exists, work with it
	else {
		std::cout << "!!! Loading files..." << std::endl;
		fp.close();
		fp.open(filename, fstream::in);

		loadData();
		std::cout << "!!! Load success." << std::endl;
		Sleep(1);
		system("CLS");
	}
}

void File::firstTimeSetup() {
	// Rooms
	Room Projector1("Projector1", 0, 40, 4, 10);
	Room Projector2("Projector2", 1, 46, 7, 12);
	Room Arena("Arena", 1, 120, 15, 5);


	// Locations
	Location Cinema("Cinema", "Str. Genso 2");
	Cinema.addEvent("Violet Evergarden", 87, Projector1, 30, 16, 27, Month::MARCH, 2023);
	Cinema.addEvent("Akiba Maid War", 88, Projector2, 15, 10, 15, Month::FEBRUARY, 2023);
	Cinema.addEvent("Death Note", 85, Projector2, 30, 16, 27, Month::MARCH, 2023);

	Location Stadium("Stadium", "Str. Light 5");
	Stadium.addEvent("Croatia v Brazilia", 120, Arena, 30, 14, 12, Month::APRIL, 2023);
	Stadium.addEvent("Bulgaria v Romania", 120, Arena, 45, 18, 19, Month::APRIL, 2023);

	// Tickets
	Ticket ticket0(Cinema.getEvents()[0], 2, 2, 1);
	Ticket ticket1(Cinema.getEvents()[0], 2, 3, 1);

	// make the locations array
	this->totalLocations = Location::getTotalLocations();
	this->locations = new Location[totalLocations];
	locations[0] = Cinema;
	locations[1] = Stadium;

	// add them to the file
	fp << totalLocations << std::endl;
	for (size_t i = 0; i < totalLocations; ++i) {
		fp << locations[i] << std::endl;
	}

	// make the tickets array
	this->totalTickets = Ticket::getTotalTickets();
	this->tickets = new Ticket[totalTickets];
	tickets[0] = ticket0;
	tickets[1] = ticket1;

	// add them to the file
	fp << totalTickets << std::endl;
	for (size_t i = 0; i < totalTickets; ++i) {
		fp << tickets[i] << std::endl;
	}

	fp.close();
	start();
}

void File::loadData() {
	// read number of locations and make a location array based on that
	fp >> this->totalLocations;
	this->locations = new Location[totalLocations];

	// read the locations
	for (size_t i = 0; i < totalLocations; ++i) {
		fp >> locations[i];
	}
	
	// read number of tickets and make a ticket array based on that
	fp >> this->totalTickets;
	this->tickets = new Ticket[totalTickets];

	// read the tickets
	for (size_t i = 0; i < totalTickets; ++i) {
		fp >> tickets[i];
	}
}

void File::end() {
	// reopen file in overwrite mode
	fp.close();
	fp.open(File::filename, fstream::out | fstream::trunc);

	// rewrite the data
	if (!fp.is_open())
		throw;
	else {
		fp << totalLocations << std::endl;
		for (size_t i = 0; i < totalLocations; ++i) {
			fp << locations[i] << std::endl;
		}
		fp << totalTickets << std::endl;
		for (size_t i = 0; i < totalTickets; ++i) {
			fp << tickets[i] << std::endl;
		}
	}
}