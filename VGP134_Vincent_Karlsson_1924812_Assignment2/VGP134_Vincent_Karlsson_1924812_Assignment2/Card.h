#pragma once

struct Card
{
	Card(int rank, int suit);

	char mRank;
	char mSuit;
	int mValue;
	
	int mID;
	static int sTrackerID; // To track if something went wrong with the static instance (was used to verify an issue where a second instance of BlackJackTable was created)
};