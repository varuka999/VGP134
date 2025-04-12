#pragma once
#include <string>

class Character
{
private:
	std::string _name;
	int _maxHealth;
	int _currentHealth;
	int _att;
	int _def;
	int _level;
	int _currentXP;
	int _xpRequired;

	void IncreaseRandomStat();
	void IncreaseMaxHealth(int amount);
public:
	Character();
	Character(std::string name, int health, int att, int def);

	void Iterate(int iterations);
	void PrintCharacterStats();

	void TakeDamage(int damage);

	std::string GetName();
	int GetCurrentHealth();
	int GetAttack();
};
