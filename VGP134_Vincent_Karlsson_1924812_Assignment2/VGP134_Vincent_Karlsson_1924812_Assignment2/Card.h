#pragma once

struct Card
{
	Card(int rank, int suit);

	char cardRank;
	char cardSuit;
	int cardValue;
	
private:
	int cardID; // Only used for debugging
	static int staticTrackerID; // To track if something went wrong with the static instance (was used to verify an issue where a second instance of BlackJackTable was created)
};