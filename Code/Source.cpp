#include <iostream>
#include <string>
#include "Headers/Seat.h"
#include "Headers/Room.h"

using namespace std;

int main() {
	Room a("Cinema", 1, 3);
	cout << a << endl;
	Room b;
	// R0-Cinema-1-3:S1-0:S2-0:S3-0:
	if (cin >> b) {
		cout << b;
	}
	return 0;
}