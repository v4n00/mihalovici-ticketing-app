#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

enum class Month {
	JANUARY = 1,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
};

// - Month operators

std::ostream& operator << (std::ostream& out, const Month& date);
std::istream& operator >> (std::istream& in, Month& date);

class Date {
private:

	friend class Event;

	unsigned int minutes = 0;
	unsigned int hour = 0;
	Month month = Month::JANUARY;
	unsigned int day = 0;
	unsigned int year = 1970;

	static const int MAX_YEAR = 2050;

	// - Setters

	void setMinutes(unsigned int minutes);
	void setHour(unsigned int hour);
	void setMonth(Month month);
	void setYear(unsigned int year);
	void setDay(unsigned int day);

	// - Private interface
	
	std::string inFullCharacters(unsigned int n);

public:

	// - Public interface
	static Date* readDate(std::ostream& out = std::cout, std::istream& in = std::cin);

	// - Getters

	unsigned int getMinutes();
	unsigned int getHour();
	Month getMonth();
	unsigned int getYear();
	unsigned int getDay();

	// - Constructors

	Date(const Date& anotherDate);
	Date(unsigned int minutes, unsigned int hour, unsigned int day, Month month, unsigned int year);
	Date();

	// - Operators

		// copy assignment

	Date operator=(const Date& anotherDate);

		// typecast operator

	explicit operator std::string();

		// compare operators

	bool operator==(const Date& anotherDate);
	bool operator!=(const Date& anotherDate);

		// stream operators

	friend std::ostream& operator << (std::ostream& out, const Date& date);
	friend std::istream& operator >> (std::istream& in, Date& date);

};