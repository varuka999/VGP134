#pragma once
#include <map>
#include "Enum.h"
#include "Team.h"
#include <vector>
#include "Schedule.h"

class SportLeague
{
public:
	SportLeague();

	void SimulateSeason();

private:
	std::map<Tier, Schedule> mTiers;
};
