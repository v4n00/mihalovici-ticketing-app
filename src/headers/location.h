#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "event.h"

class Location {
private:

	unsigned int locationId;
	char* name = nullptr;
	char* address = nullptr;
	Event* events = nullptr;
	unsigned int runningEvents = 0;

	// - Setters

	void setLocatioNId(unsigned int locationId);
	void setName(const char* name);
	void setAddress(const char* address);
	void setEvents(Event* events);
	void setRunningEvents(unsigned int runningEvents);

public:

	// - Public Interface
	
	// - Getters
	unsigned int getLocationId();
	char* getName();
	char* getAddress();
	Event* getEvents();
	unsigned int getRunningEvents();

};