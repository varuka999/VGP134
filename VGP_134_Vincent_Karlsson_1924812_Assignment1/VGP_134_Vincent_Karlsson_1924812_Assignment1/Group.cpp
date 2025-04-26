#include <iostream>
#include "Group.h"
#include "Table.h"

Group::Group()
	: groupPhase("Waiting"), currentTable(nullptr), waitTime(0), tableID(0)
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
				std::cout << "Table " << currentTable->tableID << " member " << member->name << " has started ordering.\n"; // At time
				member->memberPhase = "Ordering";
				member->waitTime = 5 + rand() % 6; // 5-10
			}
			if (member->memberPhase.compare("Ordering") == 0)
			{
				std::cout << "Table " << currentTable->tableID << " member " << member->name << " has finished ordering.\n"; // At time
				member->memberPhase = "WaitingForOrder";
				member->waitTime = 10 + rand() % 21; // 10-30
			}
			else if (member->memberPhase.compare("Waiting") == 0)
			{
				std::cout << "Table " << currentTable->tableID << " member " << member->name << " has started eating.\n"; // At time
				member->memberPhase = "Eating";
				member->waitTime = 15 + rand() % 26; // 15-40
			}
			else if (member->memberPhase.compare("Eating") == 0)
			{
				std::cout << "Table " << currentTable->tableID << " member " << member->name << " has finished eating.\n"; // At time
				member->memberPhase = "Done";
			}
		}
	}

	if (IsGroupDone() == true)
	{
		currentTable->FindGroup();
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

	std::cout << "Table " << currentTable->tableID << " is finished with their meals." << members.front()->name << " has paid the bill.\n"; // At time
	return true;
}
