#pragma once
#include <iostream>
#include <vector>
#include "Card.h"

class Hand;

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

	void PlayBlackJack();
	void UpdateHighestValue(Hand& hand);
	void RetrieveCardToDeck(std::shared_ptr<Card>& card);
	void PrintWinners();

	std::shared_ptr<Card>& ReturnTopCard();

private:
	std::vector<std::shared_ptr<Card>> mAllCards;
	std::vector<std::shared_ptr<Card>> mDeck;
	std::vector<Hand> mHighestHands;

	int mHighestHandValue; // Only among players
};