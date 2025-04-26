#include <iostream>
#include "Restaurant.h"
#include "TimeTrack.h"

Restaurant::Restaurant()
{
	Table* table2 = new Table(this, 2, 1);
	mTablesMap[table2->mNumberOfSeats].push_back(table2);
	Table* table3 = new Table(this, 3, 2);
	mTablesMap[table3->mNumberOfSeats].push_back(table3);
	Table* table4 = new Table(this, 4, 3);
	mTablesMap[table4->mNumberOfSeats].push_back(table4);
	Table* table5 = new Table(this, 5, 4);
	mTablesMap[table5->mNumberOfSeats].push_back(table5);

	for (int i = 0, j = 5; i < 4 + rand() % 4; i++, j++) // + 4-7 additional tables
	{
		Table* table = new Table(this, j);

		mTablesMap[table->mNumberOfSeats].push_back(table);
	}
}

Restaurant::~Restaurant()
{
	std::map<int, std::vector<Table*>>::iterator it;

	for (int i = 2; i <= 5; i++)
	{
		it = mTablesMap.find(i);

		if (it != mTablesMap.end())
		{
			for (Table* table : it->second)
			{
				delete table;
				table = nullptr;
			}

			it->second.clear();
		}
	}
}

void Restaurant::RunRestaurant()
{
	int shiftTime = 540; // 1 = 1 minute, 9 hour shift
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

		for (it = mTablesMap.begin(); it != mTablesMap.end(); it++)
		{
			for (int i = 0; i < it->second.size(); i++)
			{
				if (it->second[i]->mCurrentGroup != nullptr)
				{
					it->second[i]->mCurrentGroup->ProgressGroup();
				}
			}
		}

		restaurantClosed = isOpen == false && ReturnIfActiveTables() == false;
	}

	std::cout << "\n<< Restaurant Fully Closed! >>\n\n";
}

void Restaurant::NewGroupArrives()
{
	Group* group = new Group;
	
	std::cout << "\nA new group of " << group->mMembers.size() << " has arrived at the restaurant";
	PrintTime();

	if (FoundAvailableTable(group) == false)
	{
		std::cout << "The new group needed to wait in the queue.\n\n";
		mQueuedGroups.push_back(group);
	}
}

bool Restaurant::FoundAvailableTable(Group*& group)
{
	std::map<int, std::vector<Table*>>::iterator it;

	for (int i = group->mMembers.size(); i <= 5; i++)
	{
		it = mTablesMap.find(i);

		for (Table* table : it->second)
		{
			if (table->mCurrentGroup == nullptr)
			{
				table->mCurrentGroup = group;
				group->mCurrentTable = table;

				std::cout << "The new group has been seated at table " << table->mTableID << ".\n\n";
				return true;
			}
		}
	}

	return false;
}

void Restaurant::FillAvailableTable(Table* table)
{
	for (int i = 0; i < mQueuedGroups.size(); i++)
	{
		if (mQueuedGroups[i]->mMembers.size() <= table->mNumberOfSeats)
		{
			std::cout << "A queued group of " << mQueuedGroups[i]->mMembers.size() << " has been seated at table " << table->mTableID;
			PrintTime();
			std::cout << "\n";

			table->mCurrentGroup = mQueuedGroups[i];
			mQueuedGroups[i]->mCurrentTable = table;

			mQueuedGroups.erase(mQueuedGroups.begin() + i);
			break;
		}
	}
}

bool Restaurant::ReturnIfActiveTables()
{
	std::map<int, std::vector<Table*>>::iterator it;

	for (int i = 2; i <= 5; i++)
	{
		it = mTablesMap.find(i);

		for (Table* table : it->second)
		{
			if (table->mCurrentGroup != nullptr)
			{
				return true;
			}
		}
	}

	return false;
}
