#include "Restaurant.h"

Restaurant::Restaurant()
{
	for (int i = 0; i < 10; i++)
	{
		Table* table = new Table;

		_tablesMap[table->seats.size()].push_back(table);
	}
}

void Restaurant::RunRestaurant()
{

}

void Restaurant::NewGroupArrives()
{

}
