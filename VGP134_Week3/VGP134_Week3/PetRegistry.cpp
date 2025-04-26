#include "PetRegistry.h"

int PetRegistry::sPetRegistryID = 0;

PetRegistry* PetRegistry::Get()
{
	static PetRegistry sInstance;

	return &sInstance;
}

int PetRegistry::RegisterPet(std::string name, PetType type, int age)
{
	Pet pet(++sPetRegistryID);
	pet.mName = name;
	pet.mPetType = type;
	pet.mAge = age;

	mAllRegisteredPets.push_back(pet);

	return pet.mID;
}

std::vector<int> PetRegistry::GetPetIDsOfType(int type)
{
	std::vector<int> petIds;
	for (int i = 0; i < mAllRegisteredPets.size(); i++)
	{
		if (mAllRegisteredPets[i].mPetType == type || type == Invalid)
		{
			petIds.push_back(mAllRegisteredPets[i].mID);
		}
	}

	return petIds;
}

Pet PetRegistry::GetPet(int id)
{
	for (int i = 0; i < mAllRegisteredPets.size(); i++)
	{
		if (mAllRegisteredPets[i].mID == id)
		{
			return mAllRegisteredPets[i];
		}
	}

	return NULL;
}
