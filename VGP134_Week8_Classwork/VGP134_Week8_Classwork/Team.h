#pragma once
#include <string>

struct Team
{
	Team(std::string name);

	bool operator<(const Team& other) const
	{
		//return (teamScore > other.teamScore);

		if (teamScore == other.teamScore)
		{
			return teamName < other.teamName;
		}

		return teamScore > other.teamScore;
	}

	std::string teamName;
	int teamScore;
};