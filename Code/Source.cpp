#include <iostream>
#include <string>
#include "Headers/Seat.h"

int main() {
	Seat a;
	std::cout << a << std::endl;
	Seat b;
	std::cin >> b;
	std::cout << (std::string) b;
	b++;
	return 0;
}