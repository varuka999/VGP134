#include "PetStore.h"
#include "PetRegistry.h"

PetStore::PetStore()
{
	PetRegistry::Get()->RegisterPet("Puppers", Dog, 2);
	PetRegistry::Get()->RegisterPet("Kit", Cat, 3);
	PetRegistry::Get()->RegisterPet("Harv", Dog, 9);
	PetRegistry::Get()->RegisterPet("Loba", Bunny, 5);
	PetRegistry::Get()->RegisterPet("Mocks", Bird, 3);
	PetRegistry::Get()->RegisterPet("Pips", Dog, 1);
	PetRegistry::Get()->RegisterPet("Gold", Fish, 3);
	PetRegistry::Get()->RegisterPet("Yipps", Bunny, 2);
	PetRegistry::Get()->RegisterPet("Ryna", Cat, 7);
	PetRegistry::Get()->RegisterPet("Snail", Cat, 20);
	PetRegistry::Get()->RegisterPet("Goob", Fish, 1);
	PetRegistry::Get()->RegisterPet("Kore", Dog, 11);
	PetRegistry::Get()->RegisterPet("Oka", Cat, 9);
}

void PetStore::SellPet()
{
	//int randomPet = rand() % PetRegistry::
}
