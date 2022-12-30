#include "../Headers/Menu.h"

void Menu::start(int argc, char** argv) {
	file.start(argc, argv);
	int choice = -1;
	while (choice != 0) {
		choice = node0(choice);
	}
	end();
}

void Menu::end() {
	file.end();
}

// sunt constient ca putea fi scris de 100x mai bine meniul dar sincer I can't do this no more

int Menu::node0(int choice = -1) {
	system("CLS");
	cout << "--------------------------------" << endl;
	cout << "---- / / / Ticket App / / / ----" << endl;
	cout << "--------------------------------" << endl;
	cout << "1. Add a ticket" << endl;
	cout << "2. See a ticket" << endl;
	// new options
	cout << "3. Add a location" << endl;
	cout << "4. See a location" << endl;
	cout << "5. Add an event" << endl;
	cout << "--------------------------------" << endl;
	cout << "0. Exit & save" << endl;
	cout << "--------------------------------" << endl;
	cout << "> "; cin >> choice;

	if (choice >= 0 && choice <= 6) {
		switch (choice) {
		case 1:
			option1(); break;
		case 2:
			option2(); break;
		case 3:
			option3(); break;
		case 4:
			option4(); break;
		case 5:
			option5(); break;
		case 0:
			break;
		default: throw std::exception("how");
		}
	}
	else throw std::exception("Please input a correct character");

	return choice;
}

void Menu::option1() {
	int choice = -1;
	int totalLocations = Location::getTotalLocations();

	while (choice != 0) {
		system("CLS");
		cout << "--------------------------------" << endl;
		cout << "----- / / Add / Ticket / / -----" << endl;
		cout << "--------------------------------" << endl;
		cout << "Locations: " << totalLocations << endl;
		for (size_t i = 1; i <= totalLocations; ++i)
			cout << std::setw(2) << std::right << i << ". " << this->file.locations[i - 1]->getName() << endl;
		cout << "00. Back" << endl;
		cout << "> "; cin >> choice;

		if (choice >= 0 && choice <= totalLocations) {
			if (choice != 0) {
				Location* location = this->file.locations[choice - 1];
				option11(location);
				choice = 0;
			}
		}
		else throw std::exception("Please input a correct character");
	}
}

void Menu::option11(Location* location) {
	int choice = -1;
	int totalEvents = location->getRunningEvents();

	while (choice != 0) {
		system("CLS");
		cout << "--------------------------------" << endl;
		cout << "----- / / Add / Ticket / / -----" << endl;
		cout << "--------------------------------" << endl;
		cout << "Events at " << location->getName() << ": " << totalEvents << endl;
		for (size_t i = 1; i <= totalEvents; ++i)
			cout << std::setw(2) << std::right << i << ". " << location->getEvents()[i - 1]->getName()
				<< " @ " << (std::string) * (location->getEvents()[i - 1]->getStartTime()) << endl;
		cout << "00. Back" << endl;
		cout << "> "; cin >> choice;

		if (choice >= 0 && choice <= totalEvents) {
			if (choice != 0) {
				Event* event = location->getEvents()[choice - 1];
				option12(event);
				choice = 0;
			}
		}
		else throw std::exception("Please input a correct character");
	}
}

void Menu::option12(Event* event) {
	int row = 0, col = 0;
	char reserveS = 0;
	char confirmS = 0;
	bool reserve = false;
	bool confirm = false;

	system("CLS");
	cout << "--------------------------------" << endl;
	cout << "----- / / Add / Ticket / / -----" << endl;
	cout << "--------------------------------" << endl;
	event->getRoom()->printLayout();
	cout << endl << "Choose row: "; cin >> row;
	cout << "Choose column: "; cin >> col;
	cout << "Pay now [y/n]: "; cin >> reserveS;
	if (reserveS == 'y' || reserveS == 'Y') reserve = true;
	cout << "Confirm [y/n]: "; cin >> confirmS;
	if (confirmS == 'y' || confirmS == 'Y') confirm = true;

	if (confirm == true) {
		// I really hate how this works but whatever
		// as rescrie tot at this point but I cba
		file.tickets[Ticket::TOTAL_TICKETS - 1] = new Ticket(event, row, col, reserve);
		cout << endl << "Ticket successfully created." << endl;
		cout << (string)*(file.tickets[Ticket::TOTAL_TICKETS - 1]) << endl << endl;
	}
	system("pause");
}

void Menu::option2() {
	std::string id;
	system("CLS");
	cout << "--------------------------------" << endl;
	cout << "----- / / See / ticket / / -----" << endl;
	cout << "--------------------------------" << endl;
	cout << "> "; cin >> id;

	if (id.size() == 8) {
		bool isTicketValid = false;
		isTicketValid = Ticket::isTicketValid(id);

		int totalTickets = Ticket::getTotalTickets();
		int ok = 0;

		if (isTicketValid == true) {
			cout << endl << "Ticket is valid!" << endl << endl;
			for (size_t i = 0; i < totalTickets && ok == 0; ++i) {
				if (this->file.tickets[i]->id == id) {
					cout << (std::string) * (this->file.tickets[i]);
					ok = 1;
				}
			}
			cout << endl << endl;
		}
		else cout << endl << "Ticket is NOT valid!" << endl << endl;
	}
	else cout << endl << "Ticket is NOT valid!" << endl;
	system("pause");
}

void Menu::option3() {

}

void Menu::option4() {
	int choice = -1;
	int totalLocations = Location::getTotalLocations();

	while (choice != 0) {
		system("CLS");
		cout << "--------------------------------" << endl;
		cout << "---- / / See / Location / / ----" << endl;
		cout << "--------------------------------" << endl;
		cout << "Locations: " << totalLocations << endl;
		for (size_t i = 1; i <= totalLocations; ++i)
			cout << std::setw(2) << std::right << i << ". " << this->file.locations[i - 1]->getName() << endl;
		cout << "00. Back" << endl;
		cout << "> "; cin >> choice;

		if (choice >= 0 && choice <= totalLocations) {
			if (choice != 0) {
				Location* location = this->file.locations[choice - 1];
				option41(location);
				choice = 0;
			}
		}
		else throw std::exception("Please input a correct character");
	}
}

void Menu::option41(Location* location) {
	int choice = -1;
	int totalEvents = location->getRunningEvents();

	while (choice != 0) {
		system("CLS");
		cout << "--------------------------------" << endl;
		cout << "---- / / See / Location / / ----" << endl;
		cout << "--------------------------------" << endl;
		cout << (string)*location << ": " << endl;
		for (size_t i = 1; i <= totalEvents; ++i)
			cout << std::setw(2) << std::right << i << ". " << location->getEvents()[i - 1]->getName()
			<< " @ " << (std::string) * (location->getEvents()[i - 1]->getStartTime()) << endl;
		cout << "00. Back" << endl;
		cout << "> "; cin >> choice;

		if (choice >= 0 && choice <= totalEvents) {
			if (choice != 0) {
				Event* event = location->getEvents()[choice - 1];
				option42(event);
				choice = 0;
			}
		}
		else throw std::exception("Please input a correct character");
	}
}

void Menu::option42(Event* event) {
	system("CLS");
	cout << "--------------------------------" << endl;
	cout << "---- / / See / Location / / ----" << endl;
	cout << "--------------------------------" << endl;
	event->getRoom()->printLayout();
	cout << endl;
	system("pause");
}

void Menu::option5() {
	int choice = -1;
	int totalLocations = Location::getTotalLocations();

	while (choice != 0) {
		system("CLS");
		cout << "--------------------------------" << endl;
		cout << "----- / / Add // Event / / -----" << endl;
		cout << "--------------------------------" << endl;
		cout << "Locations: " << totalLocations << endl;
		for (size_t i = 1; i <= totalLocations; ++i)
			cout << std::setw(2) << std::right << i << ". " << this->file.locations[i - 1]->getName() << endl;
		cout << "00. Back" << endl;
		cout << "> "; cin >> choice;

		if (choice >= 0 && choice <= totalLocations) {
			if (choice != 0) {
				Location* location = this->file.locations[choice - 1];
				option51(location);
				choice = 0;
			}
		}
		else throw std::exception("Please input a correct character");
	}
}

void Menu::option51(Location* location) {
	system("CLS");
	cout << "--------------------------------" << endl;
	cout << "----- / / Add // Event / / -----" << endl;
	cout << "--------------------------------" << endl;

	// VERY HACKY I KNOW BUT IT IS WHAT IT IS
	std::string name = "";
	unsigned int runtime = 0;
	cout << "Event name : "; cin >> name;
	cout << "Event runtime: "; cin >> runtime;
	Room* room = Room::readRoom();
	unsigned int minutes = 0;
	unsigned int hour = 0;
	Month month = Month::JANUARY;
	unsigned int day = 0;
	unsigned int year = 1970;
	cout << "Date hour: "; cin >> hour;
	cout << "Date minutes: "; cin >> minutes;
	cout << "Date day: "; cin >> day;
	cout << "Date month: "; cin >> month;
	cout << "Date year: "; cin >> year;
	location->addEvent(name.c_str(), runtime, *room, minutes, hour, day, month, year);
	cout << endl << "Event added successfully." << endl << endl;
	system("pause");
}
