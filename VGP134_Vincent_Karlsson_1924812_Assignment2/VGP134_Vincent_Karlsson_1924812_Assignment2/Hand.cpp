#include "Hand.h"
#include "BlackJackTable.h"
#include <iostream>

void Hand::EvaluateHandValue()
{
	int totalValue = 0;
	int aceCounter = 0;

	for (int i = 0; i < mHand.size(); ++i)
	{
		if (mHand[i].get()->mRank != 'A')
		{
			totalValue += mHand[i].get()->mValue;
		}
		else
		{
			++aceCounter;
		}
	}

	for (int i = 0; i < aceCounter; ++i)
	{
		if (totalValue + 11 > 21)
		{
			totalValue += 1;
		}
		else
		{
			totalValue += 11;
		}
	}

	mHandValue = totalValue;
}

void Hand::DrawCard()
{
	mHand.push_back(BlackJackTable::Get()->ReturnTopCard());

	EvaluateHandValue();
	
	if (mHandValue > 21)
	{
		std::cout << "They Bust!\n";
	}
}

void Hand::ReturnCardsToTable()
{
	std::vector<std::shared_ptr<Card>>::iterator it;
	
	for (it = mHand.begin(); it != mHand.end();)
	{
		BlackJackTable::Get()->RetrieveCardToDeck(*it);
		it = mHand.erase(it);
	}
}

int Hand::EvaluateNextMove()
{
	if (mHandValue > 21)
	{
		std::cout << "They are bust and are out.\n";
		return 0;
	}
	else if (mHandValue >= 18)
	{
		std::cout << "They chose to stand.\n";
		return mHandValue;
	}

	while (mHandValue < 18)
	{
		if (mHandValue > 13)
		{
			bool decideToDraw = rand() % 2 ? 0 : 1; // 0-1

			if (decideToDraw == true)
			{
				std::cout << "They chose to draw!\n";
				DrawCard();
			}
			else
			{
				std::cout << "They chose to stand.\n";
				return mHandValue;
			}
		}
		else
		{
			std::cout << "They chose to draw!\n";
			DrawCard();
		}
	}

	return mHandValue > 21 ? 0 : mHandValue;
}

void Hand::PrintHand()
{
	for (int i = 0; i < mHand.size(); i++)
	{
		std::cout << mHand[i].get()->mRank << " of " << mHand[i].get()->mSuit << "\n";
	}

	std::cout << "Value: " << GetHandValue();

	if (mHandValue > 21)
	{
		std::cout << " (bust)";
	}

	std::cout << "\n\n";
}

int Hand::GetHandValue()
{
	//return mHandValue > 21 ? 0 : mHandValue;
	return mHandValue;
}
