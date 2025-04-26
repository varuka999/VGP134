#pragma once
#include <vector>
#include <queue>
#include <list>
#include "Seat.h"
#include "Group.h"

struct Table
{
	std::vector<Seat*> seats;
	Group* currentGroup;
	//std::queue<Group> quededGroups;

	//bool hasGroup;

	//bool operator<(const Table& compared) const 
	//{
	//	return seats.size() < compared.seats.size();
	//}

	Table();
};
