#pragma once
#include "Character.h"

class GameManager
{
private:
	Character _players[2];

	void CreateCharacters();
	void IterateCharacters();
	void Combat();

	int ValidateIntInput(int input);
	void ClearInputBuffer();
	void ClearLine();

public:
	GameManager();

	void RunGame();
};