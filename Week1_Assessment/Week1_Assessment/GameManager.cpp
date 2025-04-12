#include "GameManager.h"
#include <iostream>

GameManager::GameManager()
{
	srand(time(NULL));
}

void GameManager::RunGame()
{
	CreateCharacters();
	IterateCharacters();
	Combat();
}

void GameManager::CreateCharacters()
{
	std::string nameInput;

	for (int i = 0; i < 2; i++)
	{
		int healthInput = 0;
		int attInput = 0;
		int defInput = 0;

		std::cout << "Enter Character Name: ";
		std::cin >> nameInput;

		while (healthInput == 0)
		{
			std::cout << "Enter Character Health: ";
			std::cin >> healthInput;

			healthInput = ValidateIntInput(healthInput);
		}

		while (attInput == 0)
		{
			std::cout << "Enter Character Attack: ";
			std::cin >> attInput;

			attInput = ValidateIntInput(attInput);
		}

		while (defInput == 0)
		{
			std::cout << "Enter Character Defense: ";
			std::cin >> defInput;

			defInput = ValidateIntInput(defInput);
		}

		Character player(nameInput, healthInput, attInput, defInput);

		_players[i] = player;

		system("cls");
	}
}

void GameManager::IterateCharacters()
{
	int iterationsInput = 0;

	while (iterationsInput == 0)
	{
		std::cout << "Enter iterations: ";
		std::cin >> iterationsInput;

		iterationsInput = ValidateIntInput(iterationsInput);
	}

	system("cls");

	_players[0].Iterate(iterationsInput);
	_players[1].Iterate(iterationsInput);

	system("pause");
}

void GameManager::Combat()
{
	int turns = 1;
	int attackingIndex = rand() % 2; // 0-1 // Randomize who attacks first
	int defendingIndex = 1 - attackingIndex;
	int startingPlayerIndex = attackingIndex;

	std::cout << "Initiating Combat!\n\n";

	while (_players[attackingIndex].GetCurrentHealth() > 0)
	{
		if (attackingIndex == startingPlayerIndex)
		{
			std::cout << "Turn " << turns << "\n";
			turns++;
		}
		std::cout << _players[attackingIndex].GetName() << " attacks!\n";
		_players[defendingIndex].TakeDamage(_players[attackingIndex].GetAttack());
		std::cout << _players[defendingIndex].GetName() << " current health: " << _players[defendingIndex].GetCurrentHealth() << "\n\n";

		attackingIndex = 1 - attackingIndex;
		defendingIndex = 1 - defendingIndex;
	}

	std::cout << _players[defendingIndex].GetName() << " Wins!";
	std::cout << "\nFinal Health: " << _players[defendingIndex].GetCurrentHealth();
}

int GameManager::ValidateIntInput(int input)
{
	ClearInputBuffer();

	if (input <= 0)
	{
		ClearLine();

		return 0;
	}

	return input;
}

// Clears Input buffer
void GameManager::ClearInputBuffer()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Clears one line from the console window to avoid needing system("cls")
void GameManager::ClearLine()
{
	std::cout << "\x1b[A"; // Moves cursor up one line
	std::cout << "\x1b[2K"; // Delete the entire line
}
