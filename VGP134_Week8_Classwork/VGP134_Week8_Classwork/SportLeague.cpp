#include "SportLeague.h"
#include <iostream>

SportLeague::SportLeague()
{
	Team team1("Team1");
	Team team2("Team2");
	Team team3("Team3");
	Team team4("Team4");
	Schedule schedule1(team1, team2, team3, team4);

	mTiers[Tier::Tier1] = schedule1;

	Team team5("Team5");
	Team team6("Team6");
	Team team7("Team7");
	Team team8("Team8");
	Schedule schedule2(team5, team6, team7, team8);
	mTiers[Tier::Tier2] = schedule2;

	Team team9("Team9");
	Team team10("Team10");
	Team team11("Team11");
	Team team12("Team12");
	Schedule schedule3(team9, team10, team11, team12);
	mTiers[Tier::Tier3] = schedule3;

	Team team13("Team13");
	Team team14("Team14");
	Team team15("Team15");
	Team team16("Team16");
	Schedule schedule4(team13, team14, team15, team16);
	mTiers[Tier::Tier4] = schedule4;
}

void SportLeague::SimulateSeason()
{
	std::map<Tier, Schedule>::iterator it;

	for (int i = 0; i < 12; i++)
	{
		for (it = mTiers.begin(); it != mTiers.end(); ++it)
		{
			it->second.PlayMatch();
		}
	}

	for (it = mTiers.begin(); it != mTiers.end(); ++it)
	{
		std::cout << "Tier " << (int)it->first << " Table:\n";
		it->second.PrintFinalTierStats();
	}

	std::cout << "-----------------\n";

	// for each tier/schedule, extract the set here in order
	// tier 1 takes top 2 add to temp1, take last 2 add to temp2
	// tier 2 takes top 2 add to temp1, take last 2 add to temp3
	// tier 3 takes top 2 add to temp2, take last 2 add to temp4
	// tier 4 takes top 2 add to temp3, take last 2 add to temp4
	std::set<Team> tempTier1;
	std::set<Team> tempTier2;
	std::set<Team> tempTier3;
	std::set<Team> tempTier4;

	std::set<Team> newTier1;
	std::set<Team> newTier2;
	std::set<Team> newTier3;
	std::set<Team> newTier4;

	std::map<Tier, Schedule>::iterator it2 = mTiers.begin();
	tempTier1 = it2->second.ReturnTeamSet(); it2->second.ClearTeams(); ++it2;
	tempTier2 = it2->second.ReturnTeamSet(); it2->second.ClearTeams(); ++it2;
	tempTier3 = it2->second.ReturnTeamSet(); it2->second.ClearTeams(); ++it2;
	tempTier4 = it2->second.ReturnTeamSet(); it2->second.ClearTeams();

	// tier1
	std::set<Team>::iterator it3 = tempTier1.begin();
	newTier1.insert(*it3); ++it3;
	newTier1.insert(*it3); ++it3;
	newTier2.insert(*it3); ++it3;
	newTier2.insert(*it3);

	// tier2
	it3 = tempTier2.begin();
	newTier1.insert(*it3); ++it3;
	newTier1.insert(*it3); ++it3;
	newTier3.insert(*it3); ++it3;
	newTier3.insert(*it3);

	// tier3
	it3 = tempTier3.begin();
	newTier2.insert(*it3); ++it3;
	newTier2.insert(*it3); ++it3;
	newTier4.insert(*it3); ++it3;
	newTier4.insert(*it3);

	// tier4
	it3 = tempTier4.begin();
	newTier3.insert(*it3); ++it3;
	newTier3.insert(*it3); ++it3;
	newTier4.insert(*it3); ++it3;
	newTier4.insert(*it3);

	auto it4 = mTiers.begin();
	for (auto it5 = newTier1.begin(); it5 != newTier1.end(); ++it5)
	{
		it4->second.AddTeam(*it5);
	}
	it4++;

	for (auto it5 = newTier2.begin(); it5 != newTier2.end(); ++it5)
	{
		it4->second.AddTeam(*it5);
	}
	it4++;

	for (auto it5 = newTier3.begin(); it5 != newTier3.end(); ++it5)
	{
		it4->second.AddTeam(*it5);
	}
	it4++;

	for (auto it5 = newTier4.begin(); it5 != newTier4.end(); ++it5)
	{
		it4->second.AddTeam(*it5);
	}

	for (it = mTiers.begin(); it != mTiers.end(); ++it)
	{
		std::cout << "Tier " << (int)it->first << " Table:\n";
		it->second.CleanTeams();
		it->second.PrintFinalTierStats();
	}
}
