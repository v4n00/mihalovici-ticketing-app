#include "../Headers/Event.h"

unsigned int Event::TOTAL_EVENTS = 0;

// - Setters

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
	if (room != nullptr)
		this->room = new Room(*room);
	else throw;
}

// - Getters

Date* Event::getStartTime() {
	Date* rez = new Date(*this->startTime);
	return rez;
}

unsigned int Event::getRuntime() {
	return this->runtime;
}

Room* Event::getRoom() {
	return this->room;
}

// - Constructors / Destructor

Event::Event(const Event& anotherEvent) {
	this->setId(anotherEvent.id);
	this->setName(anotherEvent.name);
	this->setStartTime(anotherEvent.startTime);
	this->setRuntime(anotherEvent.runtime);
	this->setRoom(anotherEvent.room);
	++TOTAL_EVENTS;
}

Event::Event(const char* name, Date& startTime, unsigned int runtime, Room& room) {
	this->setId(++TOTAL_EVENTS);
	this->setName(name);
	this->setStartTime(&startTime);
	this->setRuntime(runtime);
	this->setRoom(&room);
}

Event::Event() {
	this->setId(++TOTAL_EVENTS);
}

Event::~Event() {
	delete[] name;
	this->name = nullptr;
	delete startTime;
	this->startTime = nullptr;
	delete room;
	this->room = nullptr;
	--TOTAL_EVENTS;
}

// - Operators

// copy assignment

Event Event::operator=(const Event& anotherEvent) {
	this->setName(anotherEvent.name);
	this->setStartTime(anotherEvent.startTime);
	this->setRuntime(anotherEvent.runtime);
	this->setRoom(anotherEvent.room);
	return *this;
}

// string typecast

Event::operator std::string() {
	std::stringstream ss;
	ss << "Event #" << id << " named \"" << name << "\" is taking place on " << (std::string)*startTime << " with a runtime of " << runtime << " minutes and takes place in Room #" << room->getId();
	return ss.str();
}

// compare operators

bool Event::operator==(const Event& anotherEvent) {
	if (this == &anotherEvent)
		return true;
	if (this->id != anotherEvent.id)
		return false;
	if (strcmp(this->name, anotherEvent.name) != 0)
		return false;
	if (this->startTime != startTime)
		return false;
	if (this->runtime != runtime)
		return false;
	if (this->room = anotherEvent.room)
		return false;
	return true;
}

bool Event::operator!=(const Event& anotherEvent) {
	return !(*this == anotherEvent);
}

// stream operators

std::ostream& operator << (std::ostream& out, const Event& event) {
	out << "E" << event.id << "-" << event.name << "-" << event.runtime << ":" << *(event.startTime) << ":" << *(event.room) << ";";
	return out;
}

std::istream& operator >> (std::istream& in, Event& event) {
	std::string id;
	std::string name;
	std::string runTime;
	if (std::getline(in, id, 'E') &&
		std::getline(in, id, '-') &&
		std::getline(in, name, '-') &&
		std::getline(in, runTime, ':')) {
			event.setId(std::stoi(id));
			event.setName(name.c_str());
			event.setRuntime(std::stoi(runTime));
	}
	else throw;
	event.startTime = new Date();
	if (!(in >> *(event.startTime)))
		throw;
	std::getline(in, id, ':');
	event.room = new Room();
	if (!(in >> *(event.room)))
		throw;
	std::getline(in, id, ';');
	return in;
}