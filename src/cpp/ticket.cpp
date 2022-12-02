#include "../headers/ticket.h"

char* Ticket::generateId() {
	char* id = new char[9];
	char hex[16] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
	srand(time(NULL));
	for (int i = 0; i < 8; ++i) {
		id[i] = hex[rand() % 16];
	}
	id[8] = '\0';
	return id;
}