#include <iostream>
#include <set>
#include "Restaurant.h"
#include "Table.h"
#include "Group.h"
#include <map>
#include <vector>

//bool FoundAvailableTableForGroup(std::map<int, std::vector<Table*>> tablesMap, Group* group);

int main()
{
	srand(time(NULL));

	Restaurant* restaurant = new Restaurant;

	restaurant->RunRestaurant();

	return 0;
}