#include "../headers/entity.h"

void Entity::setId(unsigned int id) {
	if (id != 0)
		this->id = id;
	else throw;
}

void Entity::setName(const char* name) {
	if (strlen(name) != 1)
		this->name = deepCopy(name, strlen(name) + 1);
	else throw;
}

int Entity::getId() const {
	return id;
}

char* Entity::getName() const {
	return deepCopy(name, strlen(name) + 1);
}

template<typename T>
static T* Entity::deepCopy(const T* arr, unsigned int size)
{
	if (arr == nullptr)
		throw "deepCopy receives null pointer";
	T* rez = new T[size];
	for (size_t i = 0; i < size; ++i)
		rez[i] = arr[i];
	return rez;
}