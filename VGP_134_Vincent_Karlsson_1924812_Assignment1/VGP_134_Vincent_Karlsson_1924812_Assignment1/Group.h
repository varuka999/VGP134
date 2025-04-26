#pragma once
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include "Member.h"

struct Table;

struct Group
{
	std::list<Member*> members;
	Table* currentTable;
	int waitTime;

	Group();
	void ProgressGroup();
	bool IsGroupDone();
};