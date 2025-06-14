#include "Farm.h"
#include <iostream>
#include <algorithm>
#include <random>

Farm::Farm()
	: mCurrentID(0), mTotalAdded(0), mTotalDeaths(0), mTotalSheers(0), mSheersThisUpdate(0), mSalesThisUpdate(0), mSalesValueThisUpdate(0), mTotalSheepSold(0), mTotalSheepSalesValue(0), mCurrentYear(0)
{
	srand(time(NULL));

	std::cout << "-----Farm Start-----\n";
	AddSheep(false, 10 + rand() % 11); // 10-20

	UpdateCleanup();
}

bool Farm::Update()
{
	++mCurrentYear;
	mSheersThisUpdate = 0;
	mSalesThisUpdate = 0;
	mSalesValueThisUpdate = 0;

	std::cout << "\n-----Year " << mCurrentYear << "-----\n";

	if (mSheepInFarm.empty() == false)
	{
		int wolfAttacks = 1 + rand() % 5; // 1-5

		wolfAttacks = mSheepInFarm.size() < wolfAttacks ? mSheepInFarm.size() - 1 : wolfAttacks;
		//wolfAttacks = std::min(wolfAttacks, (int)mSheepInFarm.size());

		std::random_device randomDevice;
		std::mt19937 seed(randomDevice());

		std::shuffle(mSheepInFarm.begin(), mSheepInFarm.end(), seed);

		//non shuffle method

		for (int i = 0; i < wolfAttacks; ++i)
		{
			mSheepInFarm[i].Death(false);
		}

		for (Sheep& sheep : mSheepInFarm)
		{
			sheep.AgeUp();
		}

		SellSheep();
		UpdateCleanup();
		PrintUpdateStats();

		return true;
	}
	else
	{
		std::cout << "There are no sheep remaining..\n";
		return false;
	}
}

void Farm::AddSheep(bool isChild, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		Sheep newSheep(isChild, ++mCurrentID);

		std::function<void(int, int)> birthCallback = std::bind(&Farm::OnSheepBorn, this, std::placeholders::_1, std::placeholders::_2);
		std::function<void(bool, int, int)> deathCallback = std::bind(&Farm::OnSheepDeath, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
		std::function<void()> sheerCallback = std::bind(&Farm::OnSheepSheer, this);
		newSheep.SetBirthCallback(birthCallback);
		newSheep.SetDeathCallback(deathCallback);
		newSheep.SetSheerCallback(sheerCallback);

		mNewlyAddedSheep.push(newSheep);

		++mTotalAdded;
	}
}

void Farm::PrintUpdateStats()
{
	std::cout << "\nSheep on the farm: " << mSheepInFarm.size() << "\n";
	std::cout << "Sheep sheared this year: " << mSheersThisUpdate << "\n";
	std::cout << "Sheep sold at the start of this year: " << mSalesThisUpdate << " ($" << mSalesValueThisUpdate << ")\n\n";
}

void Farm::PrintTotalStats()
{
	std::cout << "\n-----Farm End-----\n";
	std::cout << "Sheep on the farm: " << mSheepInFarm.size() << "\n";
	std::cout << "Total Sheep ever added to farm: " << mTotalAdded << "\n";
	std::cout << "Total Sheep deaths: " << mTotalDeaths << "\n";
	std::cout << "Total Sheep ever sheered: " << mTotalSheers << "\n";
	std::cout << "Total Sheep ever sold: " << mTotalSheepSold << " ($" << mTotalSheepSalesValue << ")" << "\n";
}

void Farm::OnSheepBorn(int parent, int children)
{
	AddSheep(true, children);

	std::cout << "Sheep " << parent << " gave birth to " << children << " lamb";
	if (children > 1) { std::cout << "s"; }
	std::cout << "!\n";
}

void Farm::OnSheepDeath(bool ofOldAge, int id, int age)
{
	++mTotalDeaths;

	std::cout << "Sheep " << id << " died at " << age << " years old ";

	if (ofOldAge == true)
	{
		std::cout << "to natural causes.\n";
	}
	else
	{
		std::cout << "to a wolf attack!\n";
	}
}

void Farm::OnSheepSheer()
{
	++mSheersThisUpdate;
	++mTotalSheers;
}

void Farm::SellSheep()
{
	int amountOverCap = mSheepInFarm.size() - 100;
	
	for (int i = 0; i < amountOverCap; i++)
	{
		if (mSheepInFarm[0].GetAge() <= 2)
		{
			mSalesValueThisUpdate += 300;
			mTotalSheepSalesValue += 300;
		}
		else if (mSheepInFarm[0].GetAge() <= 5)
		{
			mSalesValueThisUpdate += 500;
			mTotalSheepSalesValue += 500;
		}
		else if (mSheepInFarm[0].GetAge() <= 8)
		{
			mSalesValueThisUpdate += 150;
			mTotalSheepSalesValue += 150;
		}
		else
		{
			mSalesValueThisUpdate += 50;
			mTotalSheepSalesValue += 50;
		}

		mSheepInFarm.erase(mSheepInFarm.begin());

		++mSalesThisUpdate;
		++mTotalSheepSold;
	}
}

void Farm::UpdateCleanup()
{
	for (int i = 0; i < mSheepInFarm.size(); i++)
	{
		if (mSheepInFarm[i].IsDead() == true)
		{
			mSheepInFarm.erase(mSheepInFarm.begin() + i);
			--i;
		}
	}

	while (mNewlyAddedSheep.empty() == false)
	{
		mSheepInFarm.push_back(mNewlyAddedSheep.front());
		mNewlyAddedSheep.pop();
	}

	if (mSheepInFarm.empty() == false)
	{
		std::sort(mSheepInFarm.begin(), mSheepInFarm.end(), [](Sheep& a, Sheep& b) {return a.GetAge() < b.GetAge(); });
	}
}
