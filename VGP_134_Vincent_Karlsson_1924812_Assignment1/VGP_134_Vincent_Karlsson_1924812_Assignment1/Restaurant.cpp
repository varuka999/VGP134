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
	bool restaurantClosed = false;

	int nextGroupTimer = 0;

	std::cout << "<< Restaurant Doors Open! >>\n";

	while (restaurantClosed == false)
	{
		++timePassed;

		if (isOpen == true)
		{
			--shiftTime;
			--nextGroupTimer;

			if (nextGroupTimer <= 0)
			{
				std::cout << "\nA new group has arrived at the restaurant";
				PrintTime();
				NewGroupArrives();
				nextGroupTimer = 5 + rand() % 16; // 5-20
			}

			isOpen = shiftTime > 0;

			if (isOpen == false)
			{
				std::cout << "\n<< Restaurant Doors Closed, no new customers! >>\n\n";
			}
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

		restaurantClosed = isOpen == false && ReturnIfActiveTables() == false;
	}

	std::cout << "\n<< Restaurant Fully Close! >>\n\n";
}

void Restaurant::NewGroupArrives()
{
	Group* group = new Group;

	if (FoundAvailableTable(group) == false)
	{
		std::cout << "The new group needed to wait in the queue.\n\n";
		_queuedGroups.push_back(group);
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

				std::cout << "The new group has been seated at table " << table->tableID << ".\n\n";
				return true;
			}
		}
	}

	return false;
}

void Restaurant::FillAvailableTable(Table* table)
{
	for (int i = 0; i < _queuedGroups.size(); i++)
	{
		if (_queuedGroups[i]->members.size() <= table->seats.size())
		{
			std::cout << "\nA queued group has been seated at table " << table->tableID;
			PrintTime();
			std::cout << "\n";

			table->currentGroup = _queuedGroups[i];
			_queuedGroups[i]->currentTable = table;

			_queuedGroups.erase(_queuedGroups.begin() + i);
			break;
		}
	}
}

bool Restaurant::ReturnIfActiveTables()
{
	std::map<int, std::vector<Table*>>::iterator it;

	for (int i = 2; i <= 5; i++)
	{
		it = _tablesMap.find(i);

		for (Table* table : it->second)
		{
			if (table->currentGroup != nullptr)
			{
				return true;
			}
		}
	}

	return false;
}
