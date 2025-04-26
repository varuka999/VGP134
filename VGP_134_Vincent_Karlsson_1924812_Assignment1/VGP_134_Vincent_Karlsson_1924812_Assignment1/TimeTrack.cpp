#include "TimeTrack.h";

int timePassed = 0;

void PrintTime()
{
	int startHour = 12;

	int totalMinutes = 0 + timePassed;
	int hoursPassed = totalMinutes / 60;
	int minute = totalMinutes % 60;
	int hour = startHour + hoursPassed;

	std::cout << " at " << std::setw(2) << std::setfill('0') << hour << ":" << std::setw(2) << std::setfill('0') << minute << ".\n";
}
