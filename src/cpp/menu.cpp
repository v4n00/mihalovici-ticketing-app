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

int Menu::node0(int choice = -1) {
	system("CLS");
	cout << "--------------------------------" << endl;
	cout << "---- / / / Ticket App / / / ----" << endl;
	cout << "--------------------------------" << endl;
	cout << "1. Buy a ticket" << endl;
	cout << "2. Pay for a reserved ticket" << endl;
	cout << "3. Validate tickets" << endl;
	cout << "0. Exit & Save" << endl;
	cout << "--------------------------------" << endl;
	cout << "> "; cin >> choice;

	if (choice >= 0 && choice <= 3) {
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
	int totalLocations = Location::getTotalLocations();
	int choice;
	system("CLS");
	cout << "--------------------------------" << endl;
	cout << "----- / / Buy / Ticket / / -----" << endl;
	cout << "--------------------------------" << endl;
	cout << "Locations: " << totalLocations << endl;
	for (size_t i = 1; i <= totalLocations; ++i) {
		cout << std::setw(2) << std::right << i << ". " << this->file.locations[i - 1].getName() << endl;
	}
	cout << "00. Back" << endl;
	cout << "> "; cin >> choice;
	if (choice > 0 && choice <= totalLocations) {
		int choice1 = -1;
		while (choice1 != 0)
			choice1 = option11(choice1);
	}
	else throw std::exception("Please input a correct option");
}

int Menu::option11(int choice1 = -1) {
	Location* location = new Location;
	location = &(this->file.locations[choice1 - 1]);
	int totalEvents = location->getRunningEvents();
	int choice;
	system("CLS");
	cout << "--------------------------------" << endl;
	cout << "----- / / Buy / Ticket / / -----" << endl;
	cout << "--------------------------------" << endl;
	cout << "Events at " << location->getName() << ": " << totalEvents << endl;
	/*for (size_t i = 1; i <= totalEvents; ++i) {
		cout << std::setw(2) << std::right << i << ". " << location->getEvents();
	}*/
	cout << std::setw(2) << std::right << ". " << *(location->getEvents());
	cout << "00. Exit" << endl;
	cout << "> "; cin >> choice1;
	return choice1;
}

void Menu::option2() {
	std::string id;
	system("CLS");
	cout << "--------------------------------" << endl;
	cout << "----- / / Pay / Ticket / / -----" << endl;
	cout << "--------------------------------" << endl;
	cout << "> "; cin >> id;

	bool isTicketValid = false;
	isTicketValid = Ticket::isTicketValid(id);

	int totalTickets = Ticket::getTotalTickets();
	int ok = 0;

	if (isTicketValid == true) {
		cout << endl << "Ticket is valid!";
		for (size_t i = 0; i < totalTickets && ok == 0; ++i) {
			if (this->file.tickets[i].id == id) {
				this->file.tickets[i].payForReservation();
				ok = 1;
			}
		}
		cout << endl << "Ticket has been paid!" << endl << endl;
	}
	else cout << endl << "Ticket is NOT valid!" << endl;
	system("pause");
}

void Menu::option3() {
	std::string id;
	system("CLS");
	cout << "--------------------------------" << endl;
	cout << "---- / Validate / tickets / ----" << endl;
	cout << "--------------------------------" << endl;
	cout << "> "; cin >> id;

	bool isTicketValid = false;
	isTicketValid = Ticket::isTicketValid(id);

	int totalTickets = Ticket::getTotalTickets();
	int ok = 0;

	if (isTicketValid == true) {
		cout << endl << "Ticket is valid!" << endl << endl;
		for (size_t i = 0; i < totalTickets && ok == 0; ++i) {
			if (this->file.tickets[i].id == id) {
				cout << (std::string)this->file.tickets[i];
				ok = 1;
			}
		}
		cout << endl << endl;
	}
	else cout << endl << "Ticket is NOT valid!" << endl << endl;
	system("pause");
}