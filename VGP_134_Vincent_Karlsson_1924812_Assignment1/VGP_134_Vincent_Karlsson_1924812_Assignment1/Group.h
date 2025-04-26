#pragma once
#include <queue>
#include "Member.h"

struct Group
{
	int id;
	std::queue<Member*> members;

	Group(int i);
};