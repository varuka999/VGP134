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
	std::string groupPhase;
	Table* currentTable;
	int waitTime;
	int tableID;

	Group();
	void ProgressGroup();
	bool IsGroupDone();
};