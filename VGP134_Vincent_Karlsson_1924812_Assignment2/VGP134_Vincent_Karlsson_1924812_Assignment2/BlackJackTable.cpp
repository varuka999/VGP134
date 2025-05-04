#include "BlackJackTable.h"
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

	mDeck.clear();
	mAllCards.clear();
}

std::shared_ptr<Card>& BlackJackTable::ReturnTopCard()
{
	std::shared_ptr<Card> returnPtr = mDeck[0];
	mDeck.erase(mDeck.begin());

	return returnPtr;
}

void BlackJackTable::RetrieveCardToDeck(std::shared_ptr<Card>& card)
{
	mDeck.push_back(card);
}
