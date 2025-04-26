#include <iostream>
#include "Restaurant.h"
#include "TimeTrack.h"

Restaurant::Restaurant()
{
	Table* table2 = new Table(this, 2, 1);
	_tablesMap[table2->seats.size()].push_back(table2);
	Table* table3 = new Table(this, 3, 2);
	_tablesMap[table3->seats.size()].push_back(table3);
	Table* table4 = new Table(this, 4, 3);
	_tablesMap[table4->seats.size()].push_back(table4);
	Table* table5 = new Table(this, 5, 4);
	_tablesMap[table5->seats.size()].push_back(table5);

	for (int i = 0, j = 5; i < 4 + rand() % 4; i++, j++) // + 4-7 additional tables
	{
		Table* table = new Table(this, j);

		_tablesMap[table->seats.size()].push_back(table);
	}
}

void Restaurant::RunRestaurant()
{
	int shiftTime = 540; // 1 = 1 minute;
	bool isOpen = true;

	int nextGroupTimer = 0;

	while (isOpen)
	{
		--shiftTime;
		--nextGroupTimer;
		++timePassed;

		if (nextGroupTimer <= 0)
		{
			std::cout << "A new group has arrived at the restaurant"; // at time
			PrintTime();
			NewGroupArrives();
			nextGroupTimer = 10 + rand() % 21; // 10-30
		}

		std::map<int, std::vector<Table*>>::iterator it;

		for (it = _tablesMap.begin(); it != _tablesMap.end(); it++)
		{
			for (int i = 0; i < it->second.size(); i++)
			{
				if (it->second[i]->currentGroup != nullptr)
				{
					it->second[i]->currentGroup->ProgressGroup();
				}
			}
		}

		isOpen = shiftTime > 0;
	}

	std::cout << "Restaurant Closed!";
}

void Restaurant::NewGroupArrives()
{
	Group* group = new Group;

	if (FoundAvailableTable(group) == false)
	{
		_quededGroups.push_back(group);
	}
}

bool Restaurant::FoundAvailableTable(Group*& group)
{
	std::map<int, std::vector<Table*>>::iterator it;

	for (int i = group->members.size(); i <= 5; i++)
	{
		it = _tablesMap.find(i);

		for (Table* table : it->second)
		{
			if (table->currentGroup == nullptr)
			{
				table->currentGroup = group;
				group->currentTable = table;

				std::cout << "A new group has been seated at table " << table->tableID; // at time
				PrintTime();
				return true;
			}
		}
	}

	return false;
}

Group* Restaurant::FillAvailableTable(int seats)
{
	for (int i = 0; i < _quededGroups.size(); i++)
	{
		if (_quededGroups[i]->members.size() <= seats)
		{
			return _quededGroups[i];
		}
	}

	return nullptr;
}
