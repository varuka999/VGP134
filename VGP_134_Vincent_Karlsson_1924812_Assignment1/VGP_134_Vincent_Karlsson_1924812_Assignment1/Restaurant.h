#pragma once
#include <vector>
#include <map>
#include "Table.h"
#include "Group.h"

class Restaurant
{
private:
	std::map<int, std::vector<Table*>> _tablesMap;
	//std::vector<Group*> _allGroups;
	std::vector<Group*> _quededGroups;

public:
	Restaurant();

	void RunRestaurant();
	void NewGroupArrives();
	bool FoundAvailableTable(Group*& group);
};