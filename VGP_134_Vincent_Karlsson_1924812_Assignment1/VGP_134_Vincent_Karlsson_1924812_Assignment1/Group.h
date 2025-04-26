#pragma once
#include <list>
#include "Member.h"

struct Table;

struct Group
{
	std::list<Member*> mMembers;
	Table* mCurrentTable;
	int mWaitTime;

	std::string mMenuItemsArray[8] = { "Burger", "Pasta", "Salad", "Pizza", "Sushi", "Steak", "Soup", "Tacos" };

	Group();
	void ProgressGroup();
	bool IsGroupDone();
	std::string ReturnMenuItemName();
};