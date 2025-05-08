#include "BlackJackTable.h"
#include "Hand.h"
#include <iostream>
#include <algorithm>
#include <random>

BlackJackTable* BlackJackTable::Get()
{
	static std::unique_ptr<BlackJackTable> sInstance;

	if (sInstance == nullptr)
	{
		sInstance = std::make_unique<BlackJackTable>();
	}

	return sInstance.get();
}

BlackJackTable::BlackJackTable()
	: mHighestHandValue(0)
{
	for (int s = 1; s <= 4; ++s)
	{
		for (int r = 1; r <= 13; ++r)
		{
			std::shared_ptr<Card> cardSharedPtr = std::make_shared<Card>(r, s);
			mAllCards.push_back(cardSharedPtr);
			mDeck.push_back(cardSharedPtr);
		}
	}

	std::random_device randomDevice;
	std::mt19937 seed(randomDevice());

	std::shuffle(mDeck.begin(), mDeck.end(), seed);
}

BlackJackTable::~BlackJackTable()
{
	std::vector<std::shared_ptr<Card>>::iterator it;

	mHighestHands.clear();
	mDeck.clear();
	mAllCards.clear();
}

void BlackJackTable::PlayBlackJack()
{
	Hand players[5] = { Hand("Player1"),Hand("Player2"),Hand("Player3"),Hand("Player4"),Hand("Player5") };
	Hand dealer("Dealer");

	// Draw Phase
	std::cout << "<< Draw Phase >>\n-----------------------------\n";
	for (int i = 0; i < sizeof(players) / sizeof(players[0]); ++i)
	{
		players[i].DrawCard();
		players[i].DrawCard();
	}

	dealer.DrawCard();
	dealer.DrawCard();

	for (int i = 0; i < sizeof(players) / sizeof(players[0]); ++i)
	{
		players[i].PrintHand();
	}

	dealer.PrintHand();

	// Check any Winners after Draw Phase
	if (mHighestHandValue == 21) // Means at least 1 player has BlackJack
	{
		if (dealer.GetHandValue() == 21)
		{
			std::cout << "Its a Tie!\n";
		}
		else
		{
			BlackJackTable::Get()->PrintWinners();

			return;
		}
	}
	if (dealer.GetHandValue() == 21)
	{
		std::cout << "The House Wins!\n";
	}

	// Play Phase
	std::cout << "<< Play Phase >>\n-----------------------------\n";
	for (int i = 0; i < sizeof(players) / sizeof(players[0]); ++i)
	{
		players[i].EvaluateNextMove();
		players[i].PrintHand();
	}

	while (dealer.GetHandValue() < 17)
	{
		std::cout << "Dealer draws!\n";
		dealer.DrawCard();
	}

	dealer.PrintHand();

	int dealerValue = dealer.GetHandValue();

	// Winners after Play Phase
	if (dealerValue > mHighestHandValue && dealerValue <= 21)
	{
		std::cout << "The House wins!\n";
	}
	else if (dealerValue == mHighestHandValue)
	{
		std::cout << "It's a tie!\n";
	}
	else
	{
		BlackJackTable::Get()->PrintWinners();
	}

	for (int i = 0; i < sizeof(players) / sizeof(players[0]); i++)
	{
		players[i].ReturnCardsToTable();
	}

	dealer.ReturnCardsToTable();
}

void BlackJackTable::UpdateHighestValue(Hand& hand)
{
	int value = hand.GetHandValue();

	if (value > mHighestHandValue && value < 22)
	{
		mHighestHandValue = value;
		mHighestHands.clear();
		mHighestHands.push_back(hand);
	}
	else if (value == mHighestHandValue)
	{
		mHighestHands.push_back(hand);
	}
}

void BlackJackTable::RetrieveCardToDeck(std::shared_ptr<Card>& card)
{
	mDeck.push_back(card);
}

void BlackJackTable::PrintWinners()
{
	for (Hand player : mHighestHands)
	{
		std::cout << player.GetIdentifier() << " is a winner!";
		
		if (mHighestHandValue == 21)
		{
			std::cout << " (Blackjack!)";
		}

		std::cout << "\n";
	}
}

std::shared_ptr<Card>& BlackJackTable::ReturnTopCard()
{
	std::shared_ptr<Card> returnPtr = mDeck[0];
	mDeck.erase(mDeck.begin());

	return returnPtr;
}
