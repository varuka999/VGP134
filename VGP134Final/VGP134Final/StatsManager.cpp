#include "StatsManager.h"
#include <iostream>

const int WARNING_HUNGER_LEVEL = 3;
const int EXTREME_HUNGER_LEVEL = 5;

void StatsManager::AddPlayer(std::string name)
{
	// add a new player with the new name and set the hungerLevel to 0
	Player player;
	player.name = name;
	mPlayers.push_back(player);
}

const std::vector<Player>& StatsManager::GetPlayers() const
{
	return mPlayers;
}

int StatsManager::GetFuelAmount() const
{
	return mFuelAmount;
}

void StatsManager::UpdateFuel(int amount)
{
	// update the fuel by the amount
	mFuelAmount += amount;
	//	- fuel can't be more than 100
	if (mFuelAmount > 100)
	{
		mFuelAmount = amount;
	}
	//	- fuel can't be less than 0
	else if (mFuelAmount < 0)
	{
		mFuelAmount = 0;
	}
	//	- if amount is < 0, also increase the distance traveled by 1
	if (amount < 0)
	{
		++mDistanceTravelled;
		//mDistanceTravelled += 25; // Speed up the travel for testing
	}
}

void StatsManager::GetHungry(int playerIndex, int amount)
{
	mPlayers[playerIndex].hungerLevel += amount;
}

void StatsManager::Eat()
{
	// set all players hunger levels to 0
	for (int i = 0; i < mPlayers.size(); i++)
	{
		mPlayers[i].hungerLevel = 0;
	}
}

bool StatsManager::CanContinueTravel() const
{
	// user can travel as long as:
	//	- fuel is > 0
	if (mFuelAmount <= 0)
	{
		std::cout << "You cannot continue! You are out of fuel!\n";
		return false;
	}

	//	- no players have hungerLevel >= EXTREME_HUNGER_LEVEL
	for (Player player : mPlayers)
	{
		if (player.hungerLevel >= EXTREME_HUNGER_LEVEL)
		{
			std::cout << "You cannot continue! At least one of your members is extremely hungry!\n";
			return false;
		}
	}

	return true;
}

int StatsManager::GetDistanceTravelled() const
{
	return mDistanceTravelled;
}

void StatsManager::Print()
{
	std::cout << "ROAD TRIP PROGRESS:" << std::endl;
	std::cout << "Distance Travelled: " << mDistanceTravelled << "km" << std::endl;
	std::cout << "Fuel: " << mFuelAmount;
	if (mFuelAmount <= 0)
	{
		std::cout << " (MUST REFUEL)";
	}
	else if (mFuelAmount <= 25)
	{
		std::cout << " (Recommend Refuel)";
	}
	std::cout << std::endl << std::endl;
	std::cout << "PLAYER PROGRESS:" << std::endl;
	for (int i = 0; i < mPlayers.size(); i++)
	{
		std::cout << mPlayers[i].name << " (hunger: " << mPlayers[i].hungerLevel << ")\n";
		if (mPlayers[i].hungerLevel >= EXTREME_HUNGER_LEVEL)
		{
			std::cout << mPlayers[i].name << " MUST stop for food now, they are extremely hungry!!\n";
		}
		else if (mPlayers[i].hungerLevel >= WARNING_HUNGER_LEVEL)
		{
			std::cout << mPlayers[i].name << " should stop for food soon, they are fairly hungry!\n";
		}
	}
	// display each of the players status
	//	- show the name
	//	- show the hunger level
	//		- notify the player if they should stop soon (hunger level over warning hunger level)
	//		- notify player if they MUST stop for food (hunger level over extreme hunger level)
}
