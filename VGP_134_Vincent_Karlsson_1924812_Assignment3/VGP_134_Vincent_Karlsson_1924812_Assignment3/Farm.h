#pragma once
#include <vector>
#include <queue>
#include "Sheep.h"

class Farm
{
private:
	std::vector<Sheep> mSheepInFarm;
	std::queue<Sheep> mNewlyAddedSheep;

	int mCurrentID;
	int mTotalAdded;
	int mTotalDeaths;
	int mTotalSheers;
	int mSheersThisUpdate;
	int mSalesThisUpdate;
	int mSalesValueThisUpdate;
	int mTotalSheepSold;
	int mTotalSheepSalesValue;
	int mCurrentYear;

	void OnSheepBorn(int parentId, int lambs);
	void OnSheepDeath(bool ofOldAge, int id, int age);
	void OnSheepSheer();
	void SellSheep(); // Sells excess sheep (over 100) before the newly born are 'added' to the farm, so it will not sell sheep born in the same year/update

	void UpdateCleanup();
public:
	Farm();

	bool Update();
	void AddSheep(bool isChild, int amount);
	void PrintUpdateStats();
	void PrintTotalStats();
};