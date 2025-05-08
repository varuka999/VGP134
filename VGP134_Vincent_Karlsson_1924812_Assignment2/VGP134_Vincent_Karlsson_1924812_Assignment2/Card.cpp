#include "Card.h"

int Card::sTrackerID = 0;

Card::Card(int rank, int suit)
{
	mID = ++sTrackerID;

	switch (rank)
	{
	case 1:
		mRank = 'A';
		mValue = 11;
		break;
	case 2:
		mRank = '2';
		mValue = 2;
		break;
	case 3:
		mRank = '3';
		mValue = 3;
		break;
	case 4:
		mRank = '4';
		mValue = 4;
		break;
	case 5:
		mRank = '5';
		mValue = 5;
		break;
	case 6:
		mRank = '6';
		mValue = 6;
		break;
	case 7:
		mRank = '7';
		mValue = 7;
		break;
	case 8:
		mRank = '8';
		mValue = 8;
		break;
	case 9:
		mRank = '9';
		mValue = 9;
		break;
	case 10:
		mRank = 'T';
		mValue = 10;
		break;
	case 11:
		mRank = 'J';
		mValue = 10;
		break;
	case 12:
		mRank = 'Q';
		mValue = 10;
		break;
	case 13:
		mRank = 'K';
		mValue = 10;
		break;
	default:
		mRank = 'N';
		mValue = 0;
		break;
	}

	switch (suit)
	{
	case 1:
		mSuit = 'C';
		break;
	case 2:
		mSuit = 'D';
		break;
	case 3:
		mSuit = 'H';
		break;
	case 4:
		mSuit = 'S';
		break;
	default:
		mSuit = 'N';
		break;
	}
}
