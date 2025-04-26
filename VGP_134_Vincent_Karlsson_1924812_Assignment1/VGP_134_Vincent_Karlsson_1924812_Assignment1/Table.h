#pragma once

class Restaurant;
struct Group;

struct Table
{
	Restaurant* restaurantPtr;
	Group* currentGroup;
	int numberOfSeats;
	int tableID;

	Table(Restaurant* restPtr, int id);
	Table(Restaurant* restPtr, int numbOfSeats, int id);

	void FillTableWithNewGroup();
};
