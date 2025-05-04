#pragma once
#include <iostream>
#include <vector>
#include "Card.h"

class BlackJackTable
{
public:
	static BlackJackTable* Get();

	BlackJackTable();
	~BlackJackTable();

	BlackJackTable(BlackJackTable&) = delete;
	BlackJackTable(BlackJackTable&&) = delete;
	BlackJackTable& operator=(BlackJackTable&) = delete;
	BlackJackTable& operator=(BlackJackTable&&) = delete;

	std::shared_ptr<Card>& ReturnTopCard();
	void RetrieveCardToDeck(std::shared_ptr<Card>& card);

private:
	std::vector<std::shared_ptr<Card>> mAllCards;
	std::vector<std::shared_ptr<Card>> mDeck;
};