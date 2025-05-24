#pragma once
#include "Card.h"
#include <iostream>
#include <vector>

class Hand
{
public:
	Hand(std::string identifier);

	void EvaluateHandValue();
	void DrawCard();
	void ReturnCardsToTable();
	void EvaluateNextMove();
	void PrintHand();

	int GetHandValue();
	std::string GetIdentifier();

private:
	std::vector<std::shared_ptr<Card>> mHand;
	std::string mIdentifier;
	int mHandValue;
};