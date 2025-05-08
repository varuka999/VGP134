#include "Hand.h"
#include "BlackJackTable.h"
#include <iostream>

Hand::Hand(std::string identifier)
	: mIdentifier(identifier), mHandValue(0)
{
}

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

	if (mIdentifier != "Dealer")
	{
		BlackJackTable::Get()->UpdateHighestValue(*this);
	}

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

void Hand::EvaluateNextMove()
{
	std::cout << mIdentifier << " evaluates their hand..\n";
	if (mHandValue > 21)
	{
		std::cout << "They are bust and are out.\n";
	}
	else if (mHandValue >= 18)
	{
		std::cout << "They chose to stand.\n";
	}
	else
	{
		while (mHandValue < 18)
		{
			if (mHandValue > 13)
			{
				//bool decideToDraw = rand() % 2 ? 0 : 1; // 0-1

				if (rand() % 2 == 0)
				{
					std::cout << "They chose to draw!\n";
					DrawCard();
				}
				else
				{
					std::cout << "They chose to stand.\n";
					return;
				}
			}
			else
			{
				std::cout << "They chose to draw!\n";
				DrawCard();
			}
		}
	}
}

void Hand::PrintHand()
{
	std::cout << mIdentifier << " hand:\n";
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
	return mHandValue;
}

std::string Hand::GetIdentifier()
{
	return mIdentifier;
}
