#include "SportLeague.h"
#include "Schedule.h"
#include <iostream>

int main()
{
	srand(time(NULL));
	// 16 teams, 4 divisions
	// each team plays 12 matches within their division (vs each other 3 times)
	// top 2 teams from division move up (except div 1) and bot 2 teams move down (except div 4) base on record?

	SportLeague league;
	league.SimulateSeason();

	return 0;
}