#include <iostream>
#include "Table.h"
#include "Restaurant.h"

Table::Table(Restaurant* restPtr, int id)
	: restaurantPtr(restPtr), currentGroup(nullptr), tableID(id)
{
	numberOfSeats = 2 + rand() % 4;
}

Table::Table(Restaurant* restPtr, int numbOfSeats, int id)
	: restaurantPtr(restPtr), currentGroup(nullptr), tableID(id)
{
	numberOfSeats = numbOfSeats;
}

void Table::FillTableWithNewGroup()
{
	delete currentGroup;
	currentGroup = nullptr;

	restaurantPtr->FillAvailableTable(this);

	if (currentGroup != nullptr)
	{
		currentGroup->currentTable = this;
		currentGroup->ProgressGroup();
	}
}
