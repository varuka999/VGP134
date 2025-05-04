#pragma once
#include "Card.h"
#include <iostream>
#include <vector>

class Hand
{
public:
	void EvaluateHandValue();
	void DrawCard();
	void ReturnCardsToTable();
	int EvaluateNextMove();

	void PrintHand();

	int GetHandValue();

private:
	std::vector<std::shared_ptr<Card>> mHand;
	int mHandValue = 0;
};