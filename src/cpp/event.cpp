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
	if (room != nullptr)
		this->room = new Room(*room);
	else throw;
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
	delete[] name;
	this->name = nullptr;
	delete startTime;
	this->startTime = nullptr;
	delete room;
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

// compare operators

bool Event::operator==(const Event& anotherEvent) {
	if (this == &anotherEvent)
		return true;
	if (this->name != anotherEvent.name)
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
	out << "E" << event.name << "-" << event.runtime << ":" << *(event.startTime) << ":" << *(event.room) << ";";
	return out;
}

std::istream& operator >> (std::istream& in, Event& event) {
	std::string name;
	std::string runTime;
	if (std::getline(in, name, 'E') &&
		std::getline(in, name, '-') &&
		std::getline(in, runTime, ':')) {
			event.setName(name.c_str());
			event.setRuntime(std::stoi(runTime));
	}
	else throw;
	event.startTime = new Date();
	if (!(in >> *(event.startTime)))
		throw;
	std::getline(in, name, ':');
	event.room = new Room();
	if (!(in >> *(event.room)))
		throw;
	std::getline(in, name, ';');
}