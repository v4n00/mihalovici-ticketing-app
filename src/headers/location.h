#pragma once
#include "event.h"
#include "ticket.h"

class Location : public Entity {
private:
	char* address = nullptr;
	Event** events = nullptr;
	unsigned int runningEvents = 0;

	static unsigned int TOTAL_LOCATIONS;

	// - Setters

	void setAddress(const char* address);
	void setEvents(Event** events);
	void setRunningEvents(unsigned int runningEvents);

public:

	// - Public Interface

	// add an Event, pay attention to the arguments
	void addEvent(const char* name, unsigned int runtime, Room& room, unsigned int minutes, unsigned int hour, unsigned int day, Month month, unsigned int year);
	
	// - Getters

	char* getAddress();
	Event** getEvents();
	unsigned int getRunningEvents();

	// - Constructors / Destructor

	// copy constructor
	Location(const Location& anotherLocation);
	Location(const char* name, const char* address);
	Location(const char* name, const char* address, Event** events, unsigned int runningEvents);
	Location();
	~Location();

	// - Operators
	
		// copy assignment

	Location operator=(const Location& anotherLocation);

		// typecast operator

	explicit operator std::string();

		// compare operators

	bool operator==(const Location& anotherLocation);
	bool operator!=(const Location& anotherLocation);

		// stream operators

	friend std::ostream& operator << (std::ostream& out, const Location& location);
	friend std::istream& operator >> (std::istream& in, Location& location);
};