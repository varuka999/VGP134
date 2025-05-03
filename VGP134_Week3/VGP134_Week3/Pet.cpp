#include "Pet.h"
#include <iostream>


Pet::Pet()
	: mName(""), mPetType(PetType::Invalid), mAge(0), mID(0)
{

}
Pet::Pet(int id)
	: mName(""), mPetType(PetType::Invalid), mAge(0), mID(id)
{
}


void Pet::PrintPet()
{
	std::cout << "Name :" << mName << "\n";
	std::cout << "Type :" << (int)mPetType << "\n";
	std::cout << "Age :" << mAge << "\n\n";
}
