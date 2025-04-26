#include <iostream>
#include "Table.h"
#include "Restaurant.h"

Table::Table(Restaurant* restPtr, int id)
	: restaurantPtr(restPtr), currentGroup(nullptr), tableID(id)
{
	int randNum = 2 + rand() % 4;

	for (int i = 0; i < randNum; i++)
	{
		Seat* seat = new Seat;
		seat->id = i;

		seats.push_back(seat);
	}
}

Table::Table(Restaurant* restPtr, int numberOfSeats, int id)
	: restaurantPtr(restPtr), currentGroup(nullptr), tableID(id)
{
	for (int i = 0; i < numberOfSeats; i++)
	{
		Seat* seat = new Seat;
		seat->id = i;

		seats.push_back(seat);
	}
}

void Table::FindGroup()
{
	delete currentGroup;
	currentGroup = nullptr;

	currentGroup = restaurantPtr->FillAvailableTable(seats.size());

	if (currentGroup != nullptr)
	{
		currentGroup->ProgressGroup();
	}
}
