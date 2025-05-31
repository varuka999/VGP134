#include "Farm.h"

int main()
{
	Farm farm;

	for (int i = 0; i < 100; i++)
	{
		if (farm.Update() == false)
		{
			break;
		}
	}

	farm.PrintTotalStats();

	return 0;
}