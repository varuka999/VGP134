#pragma once
#include <vector>

class PetStore
{
public:
	std::vector<int> mPetsInStoreByID;

	PetStore();
	void SellPet();
};