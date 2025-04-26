#include <iostream>
#include "Restaurant.h"

int main()
{
	srand(time(NULL));

	Restaurant* restaurant = new Restaurant;

	restaurant->RunRestaurant();

	return 0;
}