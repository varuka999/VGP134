#include "Character.h"
#include <iostream>

Character::Character()
	: _name(""), _maxHealth(0), _currentHealth(0), _att(0), _def(0), _level(0), _currentXP(0), _xpRequired(0)
{

}

Character::Character(std::string name, int health, int att, int def)
	: _name(name), _maxHealth(health), _currentHealth(_maxHealth), _att(att), _def(def), _level(1), _currentXP(0), _xpRequired(5)
{

}

void Character::Iterate(int iterations)
{
	for (int i = 0; i < iterations; i++)
	{
		int xpGain = 1 + rand() % 5; // 1-5

		_currentXP += xpGain;

		if (xpGain >= _xpRequired)
		{
			_level++;
			_currentXP -= _xpRequired;

			IncreaseRandomStat();
		}
	}

	PrintCharacterStats();
}

void Character::IncreaseRandomStat()
{
	int statRolled = rand() % 3; // 0-2

	switch (statRolled)
	{
	case 0: _att += 3;
		break;
	case 1: _def += 3;
		break;
	case 2: IncreaseMaxHealth(3);
		break;
	default:
		break;
	}
}

void Character::PrintCharacterStats()
{
	std::cout << "Player " << _name << " stats";
	std::cout << "\nLevel: " << _level;
	std::cout << "\nHealth: " << _maxHealth;
	std::cout << "\nAttack: " << _att;
	std::cout << "\nDefense: " << _def << "\n\n";
}

void Character::TakeDamage(int damage)
{
	damage -= _def;

	if (damage <= 0)
	{
		damage = 1;
	}

	_currentHealth -= damage;

	std::cout << _name << " took " << damage << " damage! (" << _def << " blocked)\n";
}

void Character::IncreaseMaxHealth(int amount)
{
	_maxHealth += amount;
	_currentHealth = _maxHealth;
}

std::string Character::GetName()
{
	return _name;
}

int Character::GetCurrentHealth()
{
	return _currentHealth;
}

int Character::GetAttack()
{
	return _att;
}
