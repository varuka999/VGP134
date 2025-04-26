#include "Group.h"

Group::Group(int i)
	: id(i)
{
	int randNum = 2 + rand() % 4;

	for (int i = 0; i < randNum; i++)
	{
		Member* member = new Member;
		members.push(member);
	}
}
