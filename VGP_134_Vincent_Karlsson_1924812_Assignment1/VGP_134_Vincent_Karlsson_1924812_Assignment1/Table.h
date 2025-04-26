#pragma once

class Restaurant;
struct Group;

struct Table
{
	Restaurant* mRestaurantPtr;
	Group* mCurrentGroup;
	int mNumberOfSeats;
	int mTableID;

	Table(Restaurant* restPtr, int id);
	Table(Restaurant* restPtr, int numbOfSeats, int id);

	void FillTableWithNewGroup();
};
