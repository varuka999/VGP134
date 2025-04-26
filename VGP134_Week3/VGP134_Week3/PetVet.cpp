#include "PetVet.h"
#include "PetRegistry.h"
#include <iostream>

void PetVet::DoCheckup(int id)
{
	//Pet petVisited;
	//petVisited = PetRegistry::GetPet(id);

	std::cout << "Checked up " << PetRegistry::Get()->GetPet(id).mName << " (" << PetRegistry::Get()->GetPet(id).mPetType << ")\n";
	
}
