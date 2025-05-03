#include "PetRegistry.h"

int PetRegistry::sPetRegistryID = 0;

PetRegistry* PetRegistry::Get()
{
	static PetRegistry sInstance;

	return &sInstance;
}

int PetRegistry::RegisterPet(std::string name, PetType type, int age)
{
	Pet pet(sPetRegistryID++); // Start at 0
	pet.mName = name;
	pet.mPetType = type;
	pet.mAge = age;

	mAllRegisteredPets.push_back(pet);

	return pet.mID;
}

std::vector<int> PetRegistry::GetPetIDsOfType(int type)
{
	std::vector<int> petIds;

	for (auto iter = mAllRegisteredPets.begin(); iter != mAllRegisteredPets.end(); ++iter)
	{
		if ((int)iter->mPetType == type || type == (int)PetType::Invalid)
		{
			petIds.push_back(iter->mID);
		}
	}

	return petIds;
}

const Pet& PetRegistry::GetPet(int id)
{
	for (auto iter = mAllRegisteredPets.begin(); iter != mAllRegisteredPets.end(); ++iter)
	{
		if (iter->mID == id)
		{
			return *iter;
		}
	}

	return NULL;
}

void PetRegistry::RemovePet(int id)
{
	for (auto iter = mAllRegisteredPets.begin(); iter != mAllRegisteredPets.end(); ++iter)
	{
		if (iter->mID == id)
		{
			mAllRegisteredPets.erase(iter);
			break;
		}
	}
}
