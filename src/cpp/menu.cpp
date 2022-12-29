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
	cout << "6. See an event" << endl;
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