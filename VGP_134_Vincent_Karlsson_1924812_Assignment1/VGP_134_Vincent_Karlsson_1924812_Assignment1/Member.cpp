#include "Member.h"

Member::Member()
	: mMemberPhase("Waiting"), mWaitTime(0)
{
	mName = ReturnName();
}

std::string Member::ReturnName()
{
	int randomIndex = rand() % 20;

	switch (randomIndex)
	{
	case 0:
		return mNamesArray[0];
	case 1:
		return mNamesArray[1];
	case 2:
		return mNamesArray[2];
	case 3:
		return mNamesArray[3];
	case 4:
		return mNamesArray[4];
	case 5:
		return mNamesArray[5];
	case 6:
		return mNamesArray[6];
	case 7:
		return mNamesArray[7];
	case 8:
		return mNamesArray[8];
	case 9:
		return mNamesArray[9];
	case 10:
		return mNamesArray[10];
	case 11:
		return mNamesArray[11];
	case 12:
		return mNamesArray[12];
	case 13:
		return mNamesArray[13];
	case 14:
		return mNamesArray[14];
	case 15:
		return mNamesArray[15];
	case 16:
		return mNamesArray[16];
	case 17:
		return mNamesArray[17];
	case 18:
		return mNamesArray[18];
	case 19:
		return mNamesArray[19];
	default:
		return "NA";
	}
}
