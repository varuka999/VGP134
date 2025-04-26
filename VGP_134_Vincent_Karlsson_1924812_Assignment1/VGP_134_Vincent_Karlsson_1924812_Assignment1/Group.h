#pragma once
#include <list>
#include "Member.h"

struct Table;

struct Group
{
	std::list<Member*> members;
	Table* currentTable;
	int waitTime;

	std::string menuItemsArray[8] = { "Burger", "Pasta", "Salad", "Pizza", "Sushi", "Steak", "Soup", "Tacos" };

	Group();
	void ProgressGroup();
	bool IsGroupDone();
	std::string ReturnMenuItemName();
};