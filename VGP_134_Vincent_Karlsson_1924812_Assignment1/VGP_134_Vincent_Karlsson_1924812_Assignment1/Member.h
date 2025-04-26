#pragma once
#include <string>

struct Member
{
	std::string name = "";
	std::string memberPhase; //Ordering, WaitingForOrder, Eating, Done
	int waitTime;

	Member();
};