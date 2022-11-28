#include <iostream>
#include <string>
#include "Headers/Seat.h"
#include "Headers/Room.h"

using namespace std;

int main() {
	Room a("Cinema", 1, 3);
	cout << a << endl;
	Room b;
	if (cin >> b) {
		cout << b;
	}
	return 0;
}