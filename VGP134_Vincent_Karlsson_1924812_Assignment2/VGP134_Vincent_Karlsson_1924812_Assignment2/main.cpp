#include <iostream>
#include "BlackJackTable.h"
#include "Hand.h"

int main()
{
	Hand players[5];
	Hand dealer;

	BlackJackTable::Get();

	// Distribute 2 Cards to each player
	for (int i = 0; i < 5; ++i)
	{
		players[i].DrawCard();
		players[i].DrawCard();
	}

	dealer.DrawCard();
	dealer.DrawCard();

	// Show Hand Value
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Player " << i + 1 << " hand:\n"; 
		std::cout << "Value: " << players[i].ReturnHandValue() << "\n\n";
	}

	return 0;
}