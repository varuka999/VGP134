#include <iostream>
#include <iomanip>
#include "Group.h"
#include "Table.h"
#include "TimeTrack.h"

Group::Group()
	: currentTable(nullptr), waitTime(0)
{
	int randNum = 2 + rand() % 4;

	for (int i = 0; i < randNum; i++)
	{
		Member* member = new Member;
		members.push_back(member);
	}
}

void Group::ProgressGroup()
{
	for (Member* member : members)
	{
		--member->waitTime;

		if (member->waitTime <= 0)
		{
			if (member->memberPhase.compare("Waiting") == 0)
			{
				std::cout << "Table " << currentTable->tableID << " member " << member->name << " has started ordering";
				PrintTime();
				member->memberPhase = "Ordering";
				member->waitTime = 5 + rand() % 6; // 5-10
			}
			else if (member->memberPhase.compare("Ordering") == 0)
			{
				std::cout << "Table " << currentTable->tableID << " member " << member->name << " has ordered " << ReturnMenuItemName();
				PrintTime();
				member->memberPhase = "WaitingForOrder";
				member->waitTime = 10 + rand() % 21; // 10-30
			}
			else if (member->memberPhase.compare("WaitingForOrder") == 0)
			{
				std::cout << "Table " << currentTable->tableID << " member " << member->name << " has started eating";
				PrintTime();
				member->memberPhase = "Eating";
				member->waitTime = 15 + rand() % 26; // 15-40
			}
			else if (member->memberPhase.compare("Eating") == 0)
			{
				std::cout << "Table " << currentTable->tableID << " member " << member->name << " has finished eating";
				PrintTime();
				member->memberPhase = "Done";
			}
		}
	}

	if (IsGroupDone() == true)
	{
		currentTable->FillTableWithNewGroup();
	}
}

bool Group::IsGroupDone()
{
	for (Member* member : members)
	{
		if (member->memberPhase.compare("Done") != 0)
		{
			return false;
		}
	}

	std::cout << "\nTable " << currentTable->tableID << " is finished with their meals. " << members.front()->name << " has paid the bill";
	PrintTime();
	std::cout << "\n";

	for (Member* member : members)
	{
		delete member;
		member = nullptr;
	}

	members.clear();

	return true;
}



std::string Group::ReturnMenuItemName()
{
	int randomIndex = rand() % 8;

	switch (randomIndex)
	{
	case 0:
		return menuItemsArray[0];
	case 1:
		return menuItemsArray[1];
	case 2:
		return menuItemsArray[2];
	case 3:
		return menuItemsArray[3];
	case 4:
		return menuItemsArray[4];
	case 5:
		return menuItemsArray[5];
	case 6:
		return menuItemsArray[6];
	case 7:
		return menuItemsArray[7];
	default:
		return "??";
	}
}
