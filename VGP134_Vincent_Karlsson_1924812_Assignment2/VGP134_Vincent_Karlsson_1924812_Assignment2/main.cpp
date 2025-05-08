#include "BlackJackTable.h"
#include "Hand.h"
#include <iostream>
#include <vector>

int main()
{
	srand(time(NULL));

	BlackJackTable::Get()->PlayBlackJack();

	return 0;
}