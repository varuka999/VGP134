#include "Restaurant.h"
#include <iostream>
//#include <thread>
//#include <chrono>

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

	for (int i = 0, j = 5; i < 2 + rand() % 4; i++, j++) // + 2-5 additional tables
	{
		Table* table = new Table(this, j);

		_tablesMap[table->seats.size()].push_back(table);
	}
}

void Restaurant::RunRestaurant()
{
	NewGroupArrives();
	NewGroupArrives();
	NewGroupArrives();
	NewGroupArrives();
	NewGroupArrives();
	NewGroupArrives();
	NewGroupArrives();
	NewGroupArrives();
	NewGroupArrives();
	NewGroupArrives();
	NewGroupArrives();
	NewGroupArrives();
	NewGroupArrives();
	NewGroupArrives();

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

	//int shiftTime = 540; // 1 = 1 minute;
	////int shiftTime = 108; // Every 1 second = 5 minutes, Every 12 seconds = 1 hour, 
	//int nextGroupTimer = 2 + rand() % 5;

	//for (Group* group : _allGroups)
	//{
	//	--group->waitTime;

	//	if (group->waitTime <= 0 && group->groupPhase.compare("Waiting") != 0)
	//	{
	//		if (group->groupPhase.compare("Seated"))
	//		{
	//			std::cout << "Table " << group->tableID << " started their orders";
	//		}

	//	}
	//}

	//while (true)
	//{
	//	//std::this_thread::sleep_for(std::chrono::seconds(nextGroupTimer));

	//	NewGroupArrives();
	//}
}

void Restaurant::NewGroupArrives()
{
	Group* group = new Group;
	//_allGroups.push_back(group);

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
				group->tableID = table->tableID;
				//group->groupPhase = "Ordering";
				std::cout << "A new group has been seated at table " << table->tableID << ".\n";
				return true;
			}
		}
	}

	return false;
}

Group* Restaurant::FillAvailableTable()
{


	return nullptr;
}
