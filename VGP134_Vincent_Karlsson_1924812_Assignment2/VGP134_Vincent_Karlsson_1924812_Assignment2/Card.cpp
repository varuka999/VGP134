#include "Card.h"

int Card::staticTrackerID = 0;

Card::Card(int rank, int suit)
{
	cardID = ++staticTrackerID;

	switch (rank)
	{
	case 1:
		cardRank = 'A';
		cardValue = 11;
		break;
	case 2:
		cardRank = '2';
		cardValue = 2;
		break;
	case 3:
		cardRank = '3';
		cardValue = 3;
		break;
	case 4:
		cardRank = '4';
		cardValue = 4;
		break;
	case 5:
		cardRank = '5';
		cardValue = 5;
		break;
	case 6:
		cardRank = '6';
		cardValue = 6;
		break;
	case 7:
		cardRank = '7';
		cardValue = 7;
		break;
	case 8:
		cardRank = '8';
		cardValue = 8;
		break;
	case 9:
		cardRank = '9';
		cardValue = 9;
		break;
	case 10:
		cardRank = 'T';
		cardValue = 10;
		break;
	case 11:
		cardRank = 'J';
		cardValue = 10;
		break;
	case 12:
		cardRank = 'Q';
		cardValue = 10;
		break;
	case 13:
		cardRank = 'K';
		cardValue = 10;
		break;
	default:
		cardRank = 'N';
		cardValue = 0;
		break;
	}

	switch (suit)
	{
	case 1:
		cardSuit = 'C';
		break;
	case 2:
		cardSuit = 'D';
		break;
	case 3:
		cardSuit = 'H';
		break;
	case 4:
		cardSuit = 'S';
		break;
	default:
		cardSuit = 'N';
		break;
	}
}
