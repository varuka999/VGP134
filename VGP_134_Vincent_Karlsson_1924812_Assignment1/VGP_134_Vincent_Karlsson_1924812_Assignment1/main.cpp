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

	//std::vector<int> ints = { 1, 2, 3, 4, 5 };
	//
	//ints.erase(ints.begin() + 2);

	//std::map<int, std::vector<Table*>> tablesMap;
	//std::set<Table> tables;

	

	//for (int i = 0; i < 20; i++)
	//{
	//	Group* group = new Group(i);
	//}

	return 0;
}



//bool FoundAvailableTableForGroup(std::map<int, std::vector<Table*>> tablesMap, Group* group)
//{
//	std::map<int, std::vector<Table*>>::iterator it;
//
//	for (int i = group->members.size(); i <= 5; i++)
//	{
//		it = tablesMap.find(i);
//
//		for (Table* table : it->second)
//		{
//			if (table->hasGroup == false)
//			{
//				table->currentGroup = group;
//				// return
//			}
//		}
//	}
//
//	return false;
//}