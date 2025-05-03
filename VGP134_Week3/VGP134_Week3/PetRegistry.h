#pragma once
#include <vector>
#include <list>
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
	std::vector<int> GetPetIDsOfType(int type);
	const Pet& GetPet(int id);
	void RemovePet(int id);


private:
	// Hide Construtor, only singleton can create
	PetRegistry() = default; // = default; if not changing default constructor

	std::list<Pet> mAllRegisteredPets;
	static int sPetRegistryID;
};