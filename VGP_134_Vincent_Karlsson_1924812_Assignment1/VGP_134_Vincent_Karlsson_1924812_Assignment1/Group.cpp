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
				std::cout << "Table " << currentTable->tableID << " member " << member->name << " has started ordering"; // At time
				PrintTime();
				member->memberPhase = "Ordering";
				member->waitTime = 5 + rand() % 6; // 5-10
			}
			else if (member->memberPhase.compare("Ordering") == 0)
			{
				std::cout << "Table " << currentTable->tableID << " member " << member->name << " has ordered an ..."; // At time
				PrintTime();
				member->memberPhase = "WaitingForOrder";
				member->waitTime = 10 + rand() % 21; // 10-30
			}
			else if (member->memberPhase.compare("WaitingForOrder") == 0)
			{
				std::cout << "Table " << currentTable->tableID << " member " << member->name << " has started eatingn"; // At time
				PrintTime();
				member->memberPhase = "Eating";
				member->waitTime = 15 + rand() % 26; // 15-40
			}
			else if (member->memberPhase.compare("Eating") == 0)
			{
				std::cout << "Table " << currentTable->tableID << " member " << member->name << " has finished eating";   // At time
				PrintTime();
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

	std::cout << "Table " << currentTable->tableID << " is finished with their meals." << members.front()->name << " has paid the bill"; // At time
	PrintTime();
	return true;
}

//void Group::PrintTime(int time)
//{
//	int startHour = 12;
//
//	int totalMinutes = 0 + time;
//	int hoursPassed = totalMinutes / 60;
//	int minute = totalMinutes % 60;
//	int hour = startHour + hoursPassed;
//
//	std::cout << " at " << std::setw(2) << std::setfill('0') << hour << ":" << std::setw(2) << std::setfill('0') << minute << ".\n";
//}
