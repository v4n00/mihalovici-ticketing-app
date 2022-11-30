#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "room.h"
#include "date.h"

class Event {
private:
	unsigned int eventId = 0;
	char* name = nullptr;
	Date* startTime = nullptr;
	unsigned int runtime = 0;
	Room* room = nullptr;

	static unsigned int TOTAL_EVENTS;

	// - Setters

	void setEventId(unsigned int eventId);
	void setName(const char* name);
	void setStartTime(Date* startTime);
	void setRuntime(unsigned int runtime);
	void setRoom(Room* room);

public:
	// - Public interface

	// - Getters
	unsigned int getEventId();
	char* getName();
	Date* getStartTime();
	unsigned int getRuntime();
	Room* getRoom();

	// - Constructor / Destructor

	Event(const Event& anotherEvent);
	// make an event from already existing data
	Event(unsigned int eventId, const char* name, Date& startTime, unsigned int runtime, Room& room);
	// make an empty event
	Event();
	~Event();

	// - Operators

		// copy assignment

	Event operator=(const Event& anotherRoom);

		// typecast operator

	explicit operator std::string();

		// compare operators

	bool operator==(const Event& anotherEvent);
	bool operator!=(const Event& anotherEvent);

		// stream operators

	friend std::ostream& operator << (std::ostream& out, const Event& event);
	friend std::istream& operator >> (std::istream& in, Event& event);

};
