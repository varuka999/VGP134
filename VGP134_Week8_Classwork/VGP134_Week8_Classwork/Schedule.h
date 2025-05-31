#pragma once
#include <set>
#include "Team.h"

class Schedule
{
public:
	Schedule();
	Schedule(Team team1, Team team2, Team team3, Team team4);

	void AddTeam(Team team);
	void PlayMatch();
	void PrintFinalTierStats();
	void CleanTeams();
	void ClearTeams();

	std::set<Team> ReturnTeamSet();

private:
	std::set<Team> mTeamsInTier;
};