#pragma once
#include <iostream>
#include <string>

class Util {
public:
	// deep copies an array
	template<typename T>
	static T* deepCopy(const T* arr, unsigned int size);
};