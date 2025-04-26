#pragma once
#include <vector>
#include <map>
#include "Table.h"
#include "Group.h"

class Restaurant
{
public:
	Restaurant();
	~Restaurant();

	void RunRestaurant();
	void NewGroupArrives();
	bool FoundAvailableTable(Group*& group);
	void FillAvailableTable(Table* table);
	bool ReturnIfActiveTables();

private:
	std::map<int, std::vector<Table*>> mTablesMap;
	std::vector<Group*> mQueuedGroups;
	int mTotalGroups = 0;
};