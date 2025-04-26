#include "TimeTrack.h";

int timePassed = 0;

void PrintTime()
{
	int startHour = 12;
;
	int hoursPassed = timePassed / 60;
	int minute = timePassed % 60;
	int hour = (startHour + hoursPassed) % 24;

	std::cout << " at " << std::setw(2) << std::setfill('0') << hour << ":" << std::setw(2) << std::setfill('0') << minute << ".\n";
}
