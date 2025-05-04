#pragma once
#include <iostream>
#include <vector>
#include "Card.h"
#include "BlackJackTable.h"

class Hand
{
public:
	int ReturnHandValue();
	void DrawCard();
	// Return Cards;


private:
	std::vector<std::shared_ptr<Card>> mHand;
};