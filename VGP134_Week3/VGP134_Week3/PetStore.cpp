#include <iostream>
#include "PetStore.h"
#include "PetRegistry.h"

PetStore::PetStore()
{
	mPetsInStoreByID.push_back(PetRegistry::Get()->RegisterPet("Puppers", PetType::Dog, 2));
	mPetsInStoreByID.push_back(PetRegistry::Get()->RegisterPet("Kit", PetType::Cat, 3));
	mPetsInStoreByID.push_back(PetRegistry::Get()->RegisterPet("Harv", PetType::Dog, 9));
	mPetsInStoreByID.push_back(PetRegistry::Get()->RegisterPet("Berry", PetType::Dog, 10));
	mPetsInStoreByID.push_back(PetRegistry::Get()->RegisterPet("Loba", PetType::Bunny, 5));
	mPetsInStoreByID.push_back(PetRegistry::Get()->RegisterPet("Mocks", PetType::Bird, 3));
	mPetsInStoreByID.push_back(PetRegistry::Get()->RegisterPet("Pips", PetType::Dog, 1));
	mPetsInStoreByID.push_back(PetRegistry::Get()->RegisterPet("Gold", PetType::Fish, 3));
	mPetsInStoreByID.push_back(PetRegistry::Get()->RegisterPet("Yipps", PetType::Bunny, 2));
	mPetsInStoreByID.push_back(PetRegistry::Get()->RegisterPet("Ryna", PetType::Cat, 7));
	mPetsInStoreByID.push_back(PetRegistry::Get()->RegisterPet("Snail", PetType::Cat, 20));
	mPetsInStoreByID.push_back(PetRegistry::Get()->RegisterPet("Goob", PetType::Fish, 1));
	mPetsInStoreByID.push_back(PetRegistry::Get()->RegisterPet("Bloop", PetType::Fish, 2));
	mPetsInStoreByID.push_back(PetRegistry::Get()->RegisterPet("Kore", PetType::Dog, 11));
	mPetsInStoreByID.push_back(PetRegistry::Get()->RegisterPet("Faen", PetType::Cat, 9));
	mPetsInStoreByID.push_back(PetRegistry::Get()->RegisterPet("Oka", PetType::Cat, 6));
}

void PetStore::SellPet()
{
	while (true)
	{
		int petIndex = rand() % 16;

		for (int i = 0; i < mPetsInStoreByID.size(); i++)
		{
			if (mPetsInStoreByID[i] == PetRegistry::Get()->GetPet(petIndex).mID)
			{
				std::cout << "Sold " << PetRegistry::Get()->GetPet(petIndex).mName << "\n";
				mPetsInStoreByID.erase(mPetsInStoreByID.begin() + i);

				//PetRegistry::Get()->RemovePet(petIndex);

				return;
			}
		}
	}
}
