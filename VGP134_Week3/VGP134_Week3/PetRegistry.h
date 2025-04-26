#pragma once
#include <vector>
#include <string>
#include "Pet.h"

//struct Pet;

class PetRegistry
{
public:
	// Get access to the manager
	static PetRegistry* Get();
	
	// Delete Copy/Move Constructors
	PetRegistry(PetRegistry&) = delete;
	PetRegistry(PetRegistry&&) = delete;
	PetRegistry& operator=(PetRegistry&) = delete;
	PetRegistry& operator=(PetRegistry&&) = delete;

	int RegisterPet(std::string name, PetType type, int age);
	std::vector<int> GetPetIDsOfType(PetType type);
	Pet GetPet(int id);

private:
	// Hide Construtor, only singleton can create
	PetRegistry() = default; // = default; if not changing default constructor

	std::vector<Pet> mAllRegisteredPets;

	static int sPetRegistryID;
};