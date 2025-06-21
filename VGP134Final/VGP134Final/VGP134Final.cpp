// VGP134Final.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "StatsManager.h"
#include "ActionManager.h"


// Part 2: The Road Trip (70%)
//      You are on a road trip.  Manage all the members in your vehicle as well as your fuel consumption.
//      Some code is already setup:
//          - fill out the missing sections
//          - fix any errors you find
//          - there are comments throughout the code stating what each section should accomplish
//          - use error handling as well as move semantics when applicable

bool TryParse(const std::string& string, ActionType& result)
{
	try
	{
		if (string == "E" || string == "e")
		{
			result = ActionType::Eat;
			return true;
		}
		else if (string == "R" || string == "r")
		{
			result = ActionType::Refuel;
			return true;
		}
		else if (string == "C" || string == "c")
		{
			result = ActionType::Random;
			return true;
		}
	}
	catch (const std::exception&)
	{
		return false;
	}
	catch (const std::invalid_argument&)
	{
		return false;
	}
}

int main()
{
	srand(time(NULL));

	StatsManager statsManager;
	ActionManager actionManager;

	// add players to the statsManager
	statsManager.AddPlayer("Nai");
	statsManager.AddPlayer("Zoey");
	statsManager.AddPlayer("Del");

	// after adding names, add all the callbacks
	actionManager.SetFuelUpdateCallback(std::bind(&StatsManager::UpdateFuel, &statsManager, std::placeholders::_1));
	actionManager.SetEatUpdateCallback(std::bind(&StatsManager::Eat, &statsManager));
	actionManager.SetGetHungryUpdateCallback(std::bind(&StatsManager::GetHungry, &statsManager, std::placeholders::_1, std::placeholders::_2));

	// then initialize the action manager
	actionManager.Initialize(statsManager);

	// run the program
	std::string result = "";
	ActionType action = ActionType::Random;
	while (statsManager.GetDistanceTravelled() < 500)
	{
		system("cls");
		std::cout << "The Road Trip\n";
		statsManager.Print();
		std::cout << std::endl;
		// Ask user what options they would like to do next
		//      - options are to refuel, eat, or continue driving
		std::cout << "E->Eat\nR->Refuel\nC->Continue\n\nWhat do you do next?\n";
		std::getline(std::cin >> std::ws, result);

		//      - option "continue driving" is only available if statsManager.CanContinueTravel() is true
		//      - if a option is invalid, notify user
		if (TryParse(result, action) == true)
		{
			if (action == ActionType::Random && statsManager.CanContinueTravel() == false)
			{
			}
			else
			{
				actionManager.DoAction(action);
			}
		}
		else
		{
			std::cout << "Please choose a valid option!\n";
		}
		system("pause");

	}
	system("cls");
	std::cout << "The Road Trip\n";
	statsManager.Print();
	std::cout << std::endl;
	std::cout << "CONGRATULATIONS" << std::endl;
	std::cout << "You have reached your destination" << std::endl;

	// terminate action manager (deletes everything)
	actionManager.Terminate();
	return 0;
}

