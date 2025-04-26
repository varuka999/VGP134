#pragma once
#include <string>
#include "PetType.h"

struct Pet
{
	std::string mName;
	PetType mPetType;
	int mAge;
	const int mID;

	Pet();
	Pet(int id);

	void PrintPet();
};