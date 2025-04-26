#include "Table.h"
#include <iostream>

Table::Table()
	: hasGroup(false)
{
	int randNum = 2 + rand() % 4;

	for (int i = 0; i < randNum; i++)
	{
		Seat* seat = new Seat;
		seat->id = i;

		seats.push_back(seat);
	}

}