#include "../headers/location.h"

unsigned int Location::TOTAL_LOCATIONS = 0;

// - Setters

void Location::setAddress(const char* address) {
	if (strlen(address) > 1)
		this->address = Entity::deepCopy(address, strlen(address) + 1);
	else throw;
}

void Location::setEvents(Event** events) {
	if (events != nullptr) {
		this->events = new Event * [runningEvents];
		for (size_t i = 0; i < runningEvents; ++i)
			this->events[i] = new Event(*(events[i]));
	}
	else throw;
}

void Location::setRunningEvents(unsigned int runningEvents) {
	if (runningEvents != 0)
		this->runningEvents = runningEvents;
	else throw;
}

// - Public Interace

void Location::addEvent(const char* name, unsigned int runtime, Room& room, unsigned int minutes, unsigned int hour, unsigned int day, Month month, unsigned int year) {
	Event** tempEvents = new Event * [runningEvents + 1];
	if (runningEvents > 0)
		for (size_t i = 0; i < runningEvents; ++i)
			tempEvents[i] = events[i];
	Date* tempDate = new Date(minutes, hour, day, month, year);
	tempEvents[runningEvents] = new Event(name, *tempDate, runtime, room);
	this->events = tempEvents;
	++runningEvents;
}

// - Getters

int Location::getTotalLocations() {
	return Location::TOTAL_LOCATIONS;
}

Event** Location::getEvents() {
	return this->events;
}

unsigned int Location::getRunningEvents() {
	return this->runningEvents;
}

// - Constructors / Destructor

Location::Location(const Location& anotherLocation) {
	this->setId(anotherLocation.id);
	this->setName(anotherLocation.name);
	this->setAddress(anotherLocation.address);
	this->setRunningEvents(anotherLocation.runningEvents);
	this->setEvents(anotherLocation.events);
	++TOTAL_LOCATIONS;
}

Location::Location(const char* name, const char* address) {
	this->setId(++TOTAL_LOCATIONS);
	this->setName(name);
	this->setAddress(address);
	this->runningEvents = 0;
}

Location::Location(const char* name, const char* address, Event** events, unsigned int runningEvents) {
	this->setId(++TOTAL_LOCATIONS);
	this->setName(name);
	this->setAddress(address);
	this->setRunningEvents(runningEvents);
	this->setEvents(events);
}

Location::Location() {
}

Location::~Location() {
	delete[] name;
	this->name = nullptr;
	delete[] address;
	this->address = nullptr;
	for (size_t i = 0; i < runningEvents; ++i)
		delete events[i];
	delete[] events;
	--TOTAL_LOCATIONS;
}

// - Operators

// copy assignment

Location Location::operator=(const Location& anotherLocation) {
	this->setId(anotherLocation.id);
	this->setName(anotherLocation.name);
	this->setAddress(anotherLocation.address);
	this->setRunningEvents(anotherLocation.runningEvents);
	this->setEvents(anotherLocation.events);
	return *this;
}

// string typecast

Location::operator std::string() {
	std::stringstream ss;
	ss << "Location #" << id << " named \"" << name << "\" at address \"" << address << "\" has " << runningEvents << " running event(s)";
	return ss.str();
}

// compare operators

bool Location::operator==(const Location& anotherLocation) {
	if (this == &anotherLocation)
		return true;
	if (this->id != anotherLocation.id)
		return false;
	if (strcmp(this->name, anotherLocation.name) != 0)
		return false;
	if (strcmp(this->address, anotherLocation.address) != 0)
		return false;
	if (this->events != anotherLocation.events)
		return false;
	if (this->runningEvents = anotherLocation.runningEvents)
		return false;
	return true;
}

bool Location::operator!=(const Location& anotherLocation) {
	return !(*this == anotherLocation);
}

// stream operators

std::ostream& operator << (std::ostream& out, const Location& location) {
	out << "L" << location.id << "-" << location.name << "-" << location.address << "-" << location.runningEvents << ":";
	for (size_t i = 0; i < location.runningEvents; ++i)
		out << *(location.events[i]);
	out << ";";
	return out;
}

std::istream& operator >> (std::istream& in, Location& location) {
	std::string id;
	std::string name;
	std::string address;
	std::string runningEvents;
	if (std::getline(in, id, 'L') &&
		std::getline(in, id, '-') &&
		std::getline(in, name, '-') &&
		std::getline(in, address, '-') &&
		std::getline(in, runningEvents, ':')) {
		location.setId(std::stoi(id));
		location.setName(name.c_str());
		location.setAddress(address.c_str());
		location.setRunningEvents(std::stoi(runningEvents));
	}
	else throw;
	location.events = new Event * [location.runningEvents];
	for (size_t i = 0; i < location.runningEvents; ++i) {
		location.events[i] = new Event();
		if (!(in >> *(location.events[i])))
			throw;
	}
	getline(in, id, ';');
	return in;
}