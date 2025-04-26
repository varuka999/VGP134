#pragma once
#include <vector>
#include <queue>
#include <list>
#include "Seat.h"
//#include "Group.h"

class Restaurant;
struct Group;

struct Table
{
	Restaurant* restaurantPtr;
	std::vector<Seat*> seats;
	Group* currentGroup;
	int tableID;

	Table(Restaurant* restPtr, int id);
	Table(Restaurant* restPtr, int numberOfSeats, int id);
	void FindGroup();
};
