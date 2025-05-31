#include "Sheep.h"
#include <iostream>

Sheep::Sheep(bool isChild, int id)
	: mID(id), mAge(0), mIsSheered(false), mIsDead(false)
{
	if (isChild == false)
	{
		mAge = 2 + rand() % 6; // 2-7
		std::cout << "Sheep " << mID << " was added to the farm!\n";
	}
	else
	{
		std::cout << "Sheep " << mID << " was born!\n";
	}
}

int Sheep::GetID()
{
	return mID;
}

int Sheep::GetAge()
{
	return mAge;
}

bool Sheep::IsDead()
{
	return mIsDead;
}

void Sheep::AgeUp()
{
	if (mIsDead == false)
	{
		++mAge;

		if (mIsSheered == true)
		{
			mIsSheered = false;
		}

		// if >2 sheer
		if (mAge > 2)
		{
			Sheer();
		}
		// if >3 50% chance to birth (1-2)
		if (mAge > 3)
		{
			if (rand() % 2 == 0)
			{
				mBirthCallback(mID, 1 + rand() % 2); // 1-2
			}
		}
		// if >10 75% chance to die
		if (mAge > 10)
		{
			if (1 + rand() % 100 <= 75) // 1-100, <= 75
			{
				Death(true);
			}
		}
	}
}

void Sheep::Death(bool ofOldAge)
{
	mIsDead = true;
	mDeathCallback(ofOldAge, mID, mAge);
}

void Sheep::Sheer()
{
	mIsSheered = true;
	mSheerCallback();
}

void Sheep::SetBirthCallback(std::function<void(int, int)> callback)
{
	mBirthCallback = callback;
}

void Sheep::SetDeathCallback(std::function<void(bool, int, int)> callback)
{
	mDeathCallback = callback;
}

void Sheep::SetSheerCallback(std::function<void()> callback)
{
	mSheerCallback = callback;
}
