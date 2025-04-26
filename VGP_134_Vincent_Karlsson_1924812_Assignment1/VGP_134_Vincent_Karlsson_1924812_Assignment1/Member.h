#pragma once
#include <string>

struct Member
{
	std::string name;
	std::string memberPhase; // Waiting, Ordering, WaitingForOrder, Eating, Done
	int waitTime;

	std::string namesArray[20] = { "Alex", "Jordan", "Taylor", "Morgan", "Casey", "Jamie", "Riley", "Reese", "Peyton", "Skyler", "Avery", "Quinn", "Dakota", "Harper", "Rowan", "Sawyer", "Emerson", "Finley", "Kendall", "Hayden" };

	Member();
	std::string ReturnName();
};