#include "Pet.h"
#include <iostream>


Pet::Pet(int id)
	: mName(""), mPetType(Invalid), mAge(0), mID(id)
{
}

void Pet::PrintPet()
{
	std::cout << "Name :" << mName << "\n";
	std::cout << "Type :" << mPetType << "\n";
	std::cout << "Age :" << mAge << "\n\n";
}
