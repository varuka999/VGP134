#include <iostream>
#include <iomanip>
#include "Group.h"
#include "Table.h"
#include "TimeTrack.h"

Group::Group()
	: mCurrentTable(nullptr), mWaitTime(0)
{
	int randNum = 2 + rand() % 4;

	for (int i = 0; i < randNum; i++)
	{
		Member* member = new Member;
		mMembers.push_back(member);
	}
}

void Group::ProgressGroup()
{
	for (Member* member : mMembers)
	{
		--member->mWaitTime;

		if (member->mWaitTime <= 0)
		{
			if (member->mMemberPhase.compare("Waiting") == 0)
			{
				std::cout << "Table " << mCurrentTable->mTableID << " member " << member->mName << " has started ordering";
				PrintTime();
				member->mMemberPhase = "Ordering";
				member->mWaitTime = 5 + rand() % 6; // 5-10
			}
			else if (member->mMemberPhase.compare("Ordering") == 0)
			{
				std::cout << "Table " << mCurrentTable->mTableID << " member " << member->mName << " has ordered " << ReturnMenuItemName();
				PrintTime();
				member->mMemberPhase = "WaitingForOrder";
				member->mWaitTime = 10 + rand() % 21; // 10-30
			}
			else if (member->mMemberPhase.compare("WaitingForOrder") == 0)
			{
				std::cout << "Table " << mCurrentTable->mTableID << " member " << member->mName << " has started eating";
				PrintTime();
				member->mMemberPhase = "Eating";
				member->mWaitTime = 15 + rand() % 26; // 15-40
			}
			else if (member->mMemberPhase.compare("Eating") == 0)
			{
				std::cout << "Table " << mCurrentTable->mTableID << " member " << member->mName << " has finished eating";
				PrintTime();
				member->mMemberPhase = "Done";
			}
		}
	}

	if (IsGroupDone() == true)
	{
		mCurrentTable->FillTableWithNewGroup();
	}
}

bool Group::IsGroupDone()
{
	for (Member* member : mMembers)
	{
		if (member->mMemberPhase.compare("Done") != 0)
		{
			return false;
		}
	}

	std::cout << "\nTable " << mCurrentTable->mTableID << " is finished with their meals. " << mMembers.front()->mName << " has paid the bill";
	PrintTime();
	std::cout << "\n";

	for (Member* member : mMembers)
	{
		delete member;
		member = nullptr;
	}

	mMembers.clear();

	return true;
}

std::string Group::ReturnMenuItemName()
{
	int randomIndex = rand() % 8;

	switch (randomIndex)
	{
	case 0:
		return mMenuItemsArray[0];
	case 1:
		return mMenuItemsArray[1];
	case 2:
		return mMenuItemsArray[2];
	case 3:
		return mMenuItemsArray[3];
	case 4:
		return mMenuItemsArray[4];
	case 5:
		return mMenuItemsArray[5];
	case 6:
		return mMenuItemsArray[6];
	case 7:
		return mMenuItemsArray[7];
	default:
		return "??";
	}
}
