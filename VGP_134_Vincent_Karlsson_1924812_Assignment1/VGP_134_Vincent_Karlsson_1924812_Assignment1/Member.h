#pragma once
#include <string>

struct Member
{
	std::string mName;
	std::string mMemberPhase; // Waiting, Ordering, WaitingForOrder, Eating, Done
	int mWaitTime;

	std::string mNamesArray[20] = { "Alex", "Jordan", "Taylor", "Morgan", "Casey", "Jamie", "Riley", "Reese", "Peyton", "Skyler", "Avery", "Quinn", "Dakota", "Harper", "Rowan", "Sawyer", "Emerson", "Finley", "Kendall", "Hayden" };

	Member();
	std::string ReturnName();
};