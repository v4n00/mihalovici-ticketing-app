#include "../headers/date.h"

// - Date Operators

std::ostream& operator << (std::ostream& out, const Month& month) {
	switch (month) {
	case Month::JANUARY:
		out << "January"; break;
	case Month::FEBRUARY:
		out << "February"; break;
	case Month::MARCH:
		out << "March"; break;
	case Month::APRIL:
		out << "April"; break;
	case Month::MAY:
		out << "May"; break;
	case Month::JUNE:
		out << "June"; break;
	case Month::JULY:
		out << "July"; break;
	case Month::AUGUST:
		out << "August"; break;
	case Month::SEPTEMBER:
		out << "September"; break;
	case Month::OCTOBER:
		out << "October"; break;
	case Month::NOVEMBER:
		out << "November"; break;
	case Month::DECEMBER:
		out << "December"; break;
	}
	return out;
}

std::istream& operator >> (std::istream& in, Month& month) {
	int i = 0;
	if (!(in >> i) || i > 12) {
		month = Month::JANUARY;
		return in;
	}
	else
		month = (Month)i;
	return in;
}

// - Setters

void Date::setMinutes(unsigned int minutes) {
	if (minutes < 60)
		this->minutes = minutes;
	else throw;
}

void Date::setHour(unsigned int hour) {
	if (hour < 24)
		this->hour = hour;
	else throw;
}

void Date::setMonth(Month month) {
	if ((int)month > 0 || (int)month < 13)
		this->month = month;
	else throw;
}

void Date::setYear(unsigned int year) {
	if (year > 1970 && year < MAX_YEAR)
		this->year = year;
	else throw;
}

void Date::setDay(unsigned int day) {
	if (day < 31 && month == Month::JANUARY)
		this->day = day;
	if (day < 28 && month == Month::FEBRUARY)
		this->day = day;
	if (day < 31 && month == Month::MARCH)
		this->day = day;
	if (day < 30 && month == Month::APRIL)
		this->day = day;
	if (day < 31 && month == Month::MAY)
		this->day = day;
	if (day < 30 && month == Month::JUNE)
		this->day = day;
	if (day < 31 && month == Month::JULY)
		this->day = day;
	if (day < 31 && month == Month::AUGUST)
		this->day = day;
	if (day < 30 && month == Month::SEPTEMBER)
		this->day = day;
	if (day < 31 && month == Month::OCTOBER)
		this->day = day;
	if (day < 30 && month == Month::NOVEMBER)
		this->day = day;
	if (day < 31 && month == Month::DECEMBER)
		this->day = day;
	if (this->day == 0)
		throw;
}

std::string Date::inFullCharacters(unsigned int n) {
	std::string full = std::to_string(n);
	if(n >= 0 && n <= 9)
		full = "0" + std::to_string(n);
	return full;
}

// - Getters

unsigned int Date::getMinutes() {
	return this->minutes;
}

unsigned int Date::getHour() {
	return this->hour;
}

Month Date::getMonth() {
	return this->month;
}

unsigned int Date::getYear() {
	return this->year;
}

unsigned int Date::getDay() {
	return this->day;
}

// - Constructors

Date::Date(const Date& anotherDate) {
	this->setMinutes(anotherDate.minutes);
	this->setHour(anotherDate.hour);
	this->setMonth(anotherDate.month);
	this->setYear(anotherDate.year);
	this->setDay(anotherDate.day);
}

Date::Date(unsigned int minutes, unsigned int hour, unsigned int day, Month month, unsigned int year) {
	this->setMinutes(minutes);
	this->setHour(hour);
	this->setMonth(month);
	this->setYear(year);
	this->setDay(day);
}

Date::Date() {

}

// - Operators

// copy assignment

Date Date::operator=(const Date& anotherDate) {
	this->setMinutes(anotherDate.minutes);
	this->setHour(anotherDate.hour);
	this->setMonth(anotherDate.month);
	this->setYear(anotherDate.year);
	this->setDay(anotherDate.day);
	return *this;
}

// typecast operator

Date::operator std::string() {
	std::stringstream ss;
	ss << inFullCharacters(hour) << ":" << inFullCharacters(minutes) << ", " << inFullCharacters(day);
	switch (day) {
	case 1:
		ss << "st"; break;
	case 2:
		ss << "nd"; break;
	case 3:
		ss << "rd"; break;
	case 21:
		ss << "st"; break;
	case 22:
		ss << "nd"; break;
	case 23:
		ss << "rd"; break;
	case 31:
		ss << "st"; break;
	default: ss << "th";
	}
	ss << " of " << month << " " << year;
	return ss.str();
}

// compare operators

bool Date::operator==(const Date& anotherDate) {
	if (this == &anotherDate)
		return true;
	if (this->minutes != anotherDate.minutes)
		return false;
	if (this->hour != anotherDate.hour)
		return false;
	if (this->month != anotherDate.month)
		return false;
	if (this->year != anotherDate.year)
		return false;
	if (this->day != anotherDate.day)
		return false;
	return true;
}

bool Date::operator!=(const Date& anotherDate) {
	return !(*this == anotherDate);
}

// stream operators

std::ostream& operator << (std::ostream& out, const Date& date) {
	out << "D-" << date.minutes << "-" << date.hour << "-" << (int)date.month << "-" << date.year << "-" << date.day << ";";
	return out;
}

std::istream& operator >> (std::istream& in, Date& date) {
	std::string minutes;
	std::string hour;
	std::string month;
	std::string year;
	std::string day;
	if (std::getline(in, minutes, 'S') &&
		std::getline(in, minutes, '-') &&
		std::getline(in, month, '-') &&
		std::getline(in, year, '-') &&
		std::getline(in, day, ';')) {
			date.setMinutes(std::stoi(minutes));
			date.setHour(std::stoi(hour));
			date.setMonth((Month)std::stoi(month));
			date.setYear(std::stoi(year));
			date.setDay(std::stoi(day));
	}
	return in;
}