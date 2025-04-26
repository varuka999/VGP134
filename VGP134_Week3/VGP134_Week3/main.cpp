#include <iostream>
#include "Globals.h"
#include "Calculator.h"
#include "Math.h"
#include "PetRegistry.h"
#include "PetStore.h";
#include "PetVet.h"

#pragma region ClassWork
int gCount = 0;

void PrintIntTracker(int value)
{
	static int sLogTracker = 0;

	std::cout << "[" << sLogTracker++ << "] Value: " << value << "\n";
}
void PrintMathResult(int value)
{
	std::cout << "Math Result: " << value << "\n";
}
void PrintDefine(int result, int value1, int value2)
{
	std::cout << "<< value1 " << value1 << "\n";
}
void PrintCalculatorResult()
{
	std::cout << "Calculator Result: " << Calculator::GetResult() << "\n";
}
void Increment()
{
	for (int i = 0; i <= 10; i++, gCount++)
	{
		if (i < 5)
		{
			gCount = ReturnSum(gCount);
		}
		else if (i > 5)
		{
			gCount = ReturnDifference(gCount);
		}

		PrintIntTracker(gCount);
	}
}
void ClassWork()
{
	//Increment();

	//// x + 5
	//Calculator::Add(5);
	//PrintCalculatorResult();

	//// (5 + 10) * 2
	//Calculator::Add(5); Calculator::Add(10); Calculator::Multiply(2);
	//PrintCalculatorResult();

	//// 2 * 6 / 3 + 5 - 2
	//Calculator::Add(2); Calculator::Multiply(6); Calculator::Divide(3); Calculator::Add(5); Calculator::Subtract(2);
	//PrintCalculatorResult();

	//// (32 / 8) * (2 + 3) - 13
	//int div1 = Math::Divide(32, 8);
	//int add1 = Math::Add(2, 3);
	//int prod1 = Math::Multiply(div1, add1);
	//int result = Math::Subtract(prod1, 13);

	//PrintMathResult(result);

	//for (int i = 0; i < 5; ++i)
	//{
	//	int a = -10 + rand() % 31;
	//	int b = -10 + rand() % 31;
	//	std::cout << "MIN (" << a << ", " << b << "): " << MATH_MIN(a, b) << "\n";
	//	std::cout << "MAX (" << a << ", " << b << "): " << MATH_MAX(a, b) << "\n";
	//	std::cout << "CLAMP (" << a << " + " << b << "): " << MATH_CLAMP(a + b, 0, 10) << "\n";
	//	std::cout << "ABS (" << a << " - " << b << "): " << MATH_ABS(a - b) << "\n";
	//	std::cout << "\n";
	//}
}
#pragma endregion

int main()
{
	srand(time(NULL));

	PetStore petStore;
	PetVet petVet;

	for (int i = 0; i < 10; i++)
	{
		petStore.SellPet();
	}

	for (int i = Dog; i < Invalid; i++)
	{
		std::vector<int> ids = PetRegistry::Get()->GetPetIDsOfType(i);

		for (int i = 0; i < ids.size(); i++)
		{
			petVet.DoCheckup(ids[i]);
		}
	}

	//for (int i = Dog; i < Invalid; i++)
	//{
	//	for (Pet pet : PetRegistry::Get()->mAllRegisteredPets)
	//	{
	//		if (pet.mPetType == i)
	//		{
	//			petVet.DoCheckup(pet.mID);
	//		}
	//	}
	//}

	return 0;
}