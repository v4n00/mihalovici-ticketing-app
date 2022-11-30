#include "../Headers/Event.h"

// - Setters

void Event::setName(const char* name) {
	if (strlen(name) > 1)
		this->name = Util::deepCopy(name);
	else throw;
}

void Event::setStartTime(Date* startTime) {
	if (startTime != nullptr)
		this->startTime = new Date(*startTime);
	else throw;
}

void Event::setRuntime(unsigned int runtime) {
	if (runtime > 1)
		this->runtime = runtime;
	else throw;
}

void Event::setRoom(Room* room) {
	// this is intended to be a shallow copy, an event can change the room it's in
	// and most likely 1 room is not going to change at all
	this->room = room;
}

// - Getters

char* Event::getName() {
	return Util::deepCopy(this->name);
}

Date* Event::getStartTime() {
	Date* rez = new Date(*this->startTime);
	return rez;
}

unsigned int Event::getRuntime() {
	return this->runtime;
}

Room* Event::getRoom() {
	Room* rez = new Room(*this->room);
	return rez;
}

// - Constructors / Destructor

Event::Event(const Event& anotherEvent) {
	this->setName(anotherEvent.name);
	this->setStartTime(anotherEvent.startTime);
	this->setRuntime(anotherEvent.runtime);
	this->setRoom(anotherEvent.room);
}

Event::Event(const char* name, Date& startTime, unsigned int runtime, Room& room) {
	this->setName(name);
	this->setStartTime(&startTime);
	this->setRuntime(runtime);
	this->setRoom(&room);
}

Event::Event() {

}

Event::~Event() {
	delete startTime;
	this->startTime = nullptr;
	delete[] name;
	this->name = nullptr;
	// again the Room stays constant, so no need to delete the Room object
	this->room = nullptr;
}

// - Operators

// copy assignment

Event Event::operator=(const Event& anotherRoom) {
	this->setName(name);
	this->setStartTime(startTime);
	this->setRuntime(runtime);
	this->setRoom(room);
	return *this;
}

// string typecast

Event::operator std::string() {
	std::stringstream ss;
	ss << "Event \"" << name << "\" is taking place on " << (std::string)*startTime << " with a runtime of " << runtime << " minutes and takes place in " << (std::string)*room;
	return ss.str();
}