#pragma once
#include <functional>

class Sheep
{
private:
	int mID;
	int mAge;
	bool mIsSheered;
	bool mIsDead;

	std::function<void(int, int)> mBirthCallback;
	std::function<void(bool, int, int)> mDeathCallback;
	std::function<void()> mSheerCallback;

public:
	Sheep(bool isChild, int id);

	int GetID();
	int GetAge();
	bool IsDead();

	void AgeUp();
	void Death(bool ofOldAge);
	void Sheer();

	void SetBirthCallback(std::function<void(int, int)> callback);
	void SetDeathCallback(std::function<void(bool, int, int)> callback);
	void SetSheerCallback(std::function<void()> callback);
};