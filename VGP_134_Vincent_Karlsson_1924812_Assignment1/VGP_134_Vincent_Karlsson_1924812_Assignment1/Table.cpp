#include <iostream>
#include "Table.h"
#include "Restaurant.h"

Table::Table(Restaurant* restPtr, int id)
	: mRestaurantPtr(restPtr), mCurrentGroup(nullptr), mTableID(id)
{
	mNumberOfSeats = 2 + rand() % 4;
}

Table::Table(Restaurant* restPtr, int numbOfSeats, int id)
	: mRestaurantPtr(restPtr), mCurrentGroup(nullptr), mTableID(id)
{
	mNumberOfSeats = numbOfSeats;
}

void Table::FillTableWithNewGroup()
{
	delete mCurrentGroup;
	mCurrentGroup = nullptr;

	mRestaurantPtr->FillAvailableTable(this);

	if (mCurrentGroup != nullptr)
	{
		mCurrentGroup->mCurrentTable = this;
		mCurrentGroup->ProgressGroup();
	}
}
