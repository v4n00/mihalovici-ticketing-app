#pragma once
#include "seat.h"
#include "entity.h"

class Room : public Entity {
private:
	bool isVIP = false;
	unsigned int numberOfSeats = 0;
	unsigned int numberOfRows = 0;
	unsigned int pricePerSeat = 0;
	Seat** seats = nullptr;

	static unsigned int TOTAL_ROOMS;

	// - Setters

	void setType(const bool isVIP);
	void setNumberOfSeats(unsigned int numberOfSeats);
	void setNumberOfRows(unsigned int numberOfRows);
	void setPricePerSeat(unsigned int pricePerSeat);
	void setSeats(Seat** seats);

public:

	// - Public interface

	void setAllSeatsToFree();
	void printLayout(std::ostream& out = std::cout);
	// change Seat availability based on seatId
	void changeSeatAvailability(unsigned int seatId, SeatAvailability newAvailability);
	// verify the seat isnt already taken
	void checkSeatOverlap(unsigned int row, unsigned int col, SeatAvailability newAvailability);
	// change Seat availability relatively
	void changeSeatAvailability(unsigned int row, unsigned int col, SeatAvailability newAvailability);
	int getRelativeSeatId(unsigned int row, unsigned int col);
	Seat getRelativeSeat(unsigned int row, unsigned int col);
	static Seat** generateRoomOfSeats(unsigned int numberOfSeats);

	// - Getters

	bool getIsVIP();
	Seat** getSeats();
	unsigned int getNumberOfSeats();
	unsigned int getNumberOfRows();
	unsigned int getNumberOfColumns();
	unsigned int getPricePerSeat();

	// - Constructors / Destructor

	// copy constructor
	Room(const Room& anotherRoom);
	// make a room and generate 'n' number of seats
	Room(const char* name, bool isVIP, unsigned int n, unsigned int numberOfRows, unsigned int pricePerSeat);
	// make an empty room
	Room();
	~Room();
	
	// - Operators

		// copy assignment

	Room operator=(const Room& anotherRoom);

		// typecast operator

	explicit operator std::string();

		// compare operators

	bool operator==(const Room& anotherRoom);
	bool operator!=(const Room& anotherRoom);

		// stream operators

	friend std::ostream& operator << (std::ostream& out, const Room& room);
	friend std::istream& operator >> (std::istream& in, Room& room);
};