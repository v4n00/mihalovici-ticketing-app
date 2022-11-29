#include "../headers/util.h"

char* Util::deepCopy(const char* arr) {
	if (arr == nullptr) throw "Util::deepCopy receives null pointer";
	char* rez = new char[strlen(arr) + 1];
	strcpy_s(rez, strlen(arr) + 1, arr);
	return rez;
}