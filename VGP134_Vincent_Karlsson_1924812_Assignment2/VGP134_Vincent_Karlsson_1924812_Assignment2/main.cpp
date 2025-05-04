#include "BlackJackTable.h"
#include "Hand.h"
#include <iostream>
#include <vector>

int main()
{
	srand(time(NULL));

	Hand players[5];
	Hand dealer;

	int highestHandValue = 0;

	BlackJackTable::Get();

	for (int i = 0; i < 5; ++i)
	{
		players[i].DrawCard();
		players[i].DrawCard();

		if (players[i].GetHandValue() > highestHandValue && players[i].GetHandValue() < 22)
		{
			highestHandValue = players->GetHandValue();
		}
	}

	dealer.DrawCard();
	dealer.DrawCard();

	for (int i = 0; i < 5; ++i)
	{
		std::cout << "Player " << i + 1 << " hand:\n";
		players[i].PrintHand();
	}

	std::cout << "Dealers hand: \n";
	dealer.PrintHand();

	if (dealer.GetHandValue() == 21 && highestHandValue < 21)
	{
		std::cout << "The House has Blackjack!\n";
		return 0;
	}
	else if (highestHandValue == 21)
	{
		for (int i = 0; i < 5; i++)
		{
			if (players[i].GetHandValue() == highestHandValue)
			{
				std::cout << "Player " << i + 1 << " is a winner! (Blackjack!)\n";
			}
		}

		return 0;
	}

	for (int i = 0; i < 5; ++i)
	{
		std::cout << "Player " << i + 1 << " evaluates their hand..\n";
		int playerHandValue = players[i].EvaluateNextMove();

		if (playerHandValue > highestHandValue)
		{
			highestHandValue = playerHandValue;
		}

		players[i].PrintHand();
	}

	std::cout << "The dealers evaluates their hand..\n";
	while (dealer.GetHandValue() < 17)
	{
		std::cout << "Dealer draws!\n";
		dealer.DrawCard();
	}

	std::cout << "Dealers hand: \n";
	dealer.PrintHand();

	if (dealer.GetHandValue() > highestHandValue && dealer.GetHandValue() <= 21)
	{
		std::cout << "The House wins!\n";
	}
	else if (dealer.GetHandValue() == highestHandValue)
	{
		std::cout << "It's a tie!\n";
		// Push?
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			if (players[i].GetHandValue() == highestHandValue)
			{
				std::cout << "Player " << i + 1 << " is a winner!";

				if (highestHandValue == 21)
				{
					std::cout << " (Blackjack!)";
				}

				std::cout << "\n";
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		players[i].ReturnCardsToTable();
	}

	dealer.ReturnCardsToTable();

	return 0;
}