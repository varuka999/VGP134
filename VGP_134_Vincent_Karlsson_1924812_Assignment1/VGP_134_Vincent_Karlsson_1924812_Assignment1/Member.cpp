#include "Member.h"

Member::Member()
	: memberPhase("Waiting"), waitTime(0)
{
	name = ReturnName();
}

std::string Member::ReturnName()
{
	int randomIndex = rand() % 20;

	switch (randomIndex)
	{
	case 0:
		return namesArray[0];
	case 1:
		return namesArray[1];
	case 2:
		return namesArray[2];
	case 3:
		return namesArray[3];
	case 4:
		return namesArray[4];
	case 5:
		return namesArray[5];
	case 6:
		return namesArray[6];
	case 7:
		return namesArray[7];
	case 8:
		return namesArray[8];
	case 9:
		return namesArray[9];
	case 10:
		return namesArray[10];
	case 11:
		return namesArray[11];
	case 12:
		return namesArray[12];
	case 13:
		return namesArray[13];
	case 14:
		return namesArray[14];
	case 15:
		return namesArray[15];
	case 16:
		return namesArray[16];
	case 17:
		return namesArray[17];
	case 18:
		return namesArray[18];
	case 19:
		return namesArray[19];
	default:
		return "NA";
	}
}
