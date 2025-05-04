#pragma once

struct Card
{
	Card(int rank, int suit);

	char mRank;
	char mSuit;
	int mValue;
};