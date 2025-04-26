#pragma once
#include <vector>
#include <map>
#include "Table.h"
#include "Group.h"

class Restaurant
{
private:
	std::map<int, std::vector<Table*>> _tablesMap;
	std::vector<Group*> _queuedGroups;
	int _totalGroups = 0;

public:
	Restaurant();
	~Restaurant();

	void RunRestaurant();
	void NewGroupArrives();
	bool FoundAvailableTable(Group*& group);
	void FillAvailableTable(Table* table);
	bool ReturnIfActiveTables();
};