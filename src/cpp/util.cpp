#include "../headers/util.h"

template<typename T>
inline T* Util::deepCopy(const T* arr, unsigned int size)
{
	if (arr == nullptr)
		throw "Util::deepCopy receives null pointer";
	T* rez = new T[size];
	for (size_t i = 0; i < size; ++i)
		rez[i] = arr[i];
	return rez;
}