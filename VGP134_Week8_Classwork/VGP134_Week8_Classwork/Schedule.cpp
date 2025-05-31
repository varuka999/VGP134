#include "Schedule.h"
#include <iostream>
#include <vector>

Schedule::Schedule()
{
}

Schedule::Schedule(Team team1, Team team2, Team team3, Team team4)
{
	mTeamsInTier.insert(team1);
	mTeamsInTier.insert(team2);
	mTeamsInTier.insert(team3);
	mTeamsInTier.insert(team4);
}

void Schedule::AddTeam(Team team)
{
	mTeamsInTier.insert(team);
}

void Schedule::PlayMatch()
{
	std::vector<Team> tempTeams;

	for (Team team : mTeamsInTier)
	{
		tempTeams.push_back(team);
	}

	ClearTeams();

	for (int i = 0; i < tempTeams.size(); ++i)
	{
		tempTeams[i].teamScore += rand() % 3; // 0-2
	}

	for (Team team : tempTeams)
	{
		mTeamsInTier.insert(team);
	}
}

void Schedule::PrintFinalTierStats()
{
	for (Team team : mTeamsInTier)
	{
		std::cout << team.teamName << ": " << team.teamScore << "\n";
	}

	std::cout << "\n";
	//for (std::set<Team>::iterator it = mTeamsInTier.begin(); it != mTeamsInTier.end(); ++it)
	//{
	//	std::cout << it->teamName << ": " << it->teamScore;
	//}
}

void Schedule::CleanTeams()
{
	std::vector<Team> tempTeams;

	for (Team team : mTeamsInTier)
	{
		tempTeams.push_back(team);
	}

	ClearTeams();

	for (int i = 0; i < tempTeams.size(); ++i)
	{
		tempTeams[i].teamScore = 0; // 0-2
	}

	for (Team team : tempTeams)
	{
		mTeamsInTier.insert(team);
	}
}

void Schedule::ClearTeams()
{
	mTeamsInTier.clear();
}

std::set<Team> Schedule::ReturnTeamSet()
{
	return mTeamsInTier;
}
