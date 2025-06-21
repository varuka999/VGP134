// Assignment4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include "WeaponContainer.h"

void ClearConsoleLines(int lines)
{
	for (int i = 0; i < lines; i++)
	{
		std::cout << "\x1b[1A"; // Move Line
		std::cout << "\x1b[2K"; // Delete Line
	}
}

void ClearInputBuffer()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool TryParse(const std::string& string, Weapon::WeaponType& result)
{
	try
	{
		if (string == "Sword")
		{
			result = Weapon::Sword;
			return true;
		}
		else if (string == "Bow")
		{
			result = Weapon::Bow;
			return true;
		}
		else if (string == "Staff")
		{
			result = Weapon::Staff;
			return true;
		}
		else if (string == "Spear")
		{
			result = Weapon::Spear;
			return true;
		}
		else if (string == "Hammer")
		{
			result = Weapon::Hammer;
			return true;
		}
		else if (string == "Axe")
		{
			result = Weapon::Axe;
			return true;
		}
		else
		{
			if (string != "q")
			{
				std::cout << "Enter a valid Weapon Type!\n";
				system("pause");
			}
			return false;
		}
	}

	catch (const std::invalid_argument&)
	{
		return false;
	}
}

bool TryParse(const std::string& string, int& result)
{
	try
	{
		result = std::stoi(string);
		result = std::max(1, result); // Caps floor to 1;
		return true;
	}

	catch (const std::invalid_argument&)
	{
		if (string != "q")
		{
			std::cout << "Please input a valid integer!\n";
			system("pause");
			ClearConsoleLines(3);
		}
		return false;
	}
}

bool TryParse(const std::string& string)
{
	try
	{
		if (string == "Damage")
		{
			return true;
		}
		else if (string == "Range")
		{
			return true;
		}
		else if (string == "Ammo")
		{
			return true;
		}
		else
		{
			if (string != "q")
			{
				std::cout << "Not a valid stat to change!\n";
				system("pause");
			}
		}
	}

	catch (const std::invalid_argument&)
	{

		return false;
	}
}

void const PrintWeaponInfo(Weapon& viewWeapon)
{
	std::cout << "Name: " << viewWeapon.name << "\n";
	std::cout << "Damage: " << viewWeapon.damage << "\n";
	std::cout << "Ranger: " << viewWeapon.range << "\n";
	std::cout << "Ammo: " << viewWeapon.maxAmmo << "\n\n";
}

Weapon CreateWeapon(Weapon::WeaponType weaponType, const std::string& name, int damage, int range, int maxAmmo, bool starter = false)
{
	Weapon newWeapon;
	newWeapon.weaponType = weaponType;
	newWeapon.name = name;
	newWeapon.damage = damage;
	newWeapon.range = range;
	newWeapon.maxAmmo = maxAmmo;
	newWeapon.starter = starter;
	return newWeapon;
}


void ViewAllWeapons(WeaponContainer& weaponContainer)
{
	weaponContainer.Print();
}

void ViewWeaponsOfType(WeaponContainer& weaponContainer)
{
	std::string response = "";
	bool exit = false;

	while (!exit)
	{
		system("cls");
		std::cout << "View Weapons Of Type\n";
		std::cout << "Specify Weapon Type (q to go back):\n";

		std::cin >> response;

		Weapon::WeaponType responseType;

		if (TryParse(response, responseType) == true)
		{
			weaponContainer.Print(responseType);
		}

		if (response == "q")
		{
			exit = true;
			continue;
		}

		system("pause");
	}
}

void ViewWeapon(WeaponContainer& weaponContainer)
{
	std::string response = "";

	system("cls");
	std::cout << "Weapon Name: ";
	std::getline(std::cin >> std::ws, response);

	Weapon viewWeapon = weaponContainer.GetWeapon(response);

	if (viewWeapon.weaponType != Weapon::Invalid && viewWeapon.weaponType != Weapon::Count)
	{
		PrintWeaponInfo(viewWeapon);
	}
	else
	{
		std::cout << "No weapon with that names exists!\n";
	}
}

void AddWeapon(WeaponContainer& weaponContainer)
{
	std::string weaponName = "";
	std::string weaponTypeString = "";
	std::string damageString = "";
	std::string rangeString = "";
	std::string maxAmmoString = "";
	Weapon::WeaponType weaponType = Weapon::Invalid;
	int damage = 0;
	int range = 0;
	int maxAmmo = 0;

	system("cls");
	std::cout << "Press q to cancel weapon creation at any point\n\n";

	while (true)
	{
		std::cout << "Weapon Name: ";
		std::getline(std::cin >> std::ws, weaponName); // Needed the std::ws to skip newlines and empty spaces before the input.

		if (weaponContainer.HasWeaponName(weaponName) == true)
		{
			std::cout << "Weapon name already exists!\n";
			system("pause");
			ClearConsoleLines(3);
			continue;
		}
		else
		{
			break;
		}
	}
	if (weaponName == "q")
	{
		std::cout << "\nCancelled Weapon Creation!\n";
		return;
	}

	while (true)
	{
		std::cout << "Weapon Type (Sword, Bow, Staff, Spear, Hammer, Axe): ";
		std::getline(std::cin >> std::ws, weaponTypeString);

		if (TryParse(weaponTypeString, weaponType) == true)
		{
			break;
		}

		if (weaponTypeString == "q")
		{
			std::cout << "\nCancelled Weapon Creation!\n";
			return;
		}

		ClearConsoleLines(3);
	}

	while (true)
	{
		std::cout << "Weapon Damage: ";
		std::cin >> damageString;

		if (TryParse(damageString, damage) == true)
		{
			ClearConsoleLines(1);
			std::cout << "Weapon Damage: " << damage << "\n";
			break;
		}

		if (damageString == "q")
		{
			std::cout << "\nCancelled Weapon Creation!\n";
			return;
		}
	}

	while (true)
	{
		std::cout << "Weapon Range: ";
		std::cin >> rangeString;

		if (TryParse(rangeString, range) == true)
		{
			ClearConsoleLines(1);
			std::cout << "Weapon Range: " << range << "\n";
			break;
		}
		if (rangeString == "q")
		{
			std::cout << "\nCancelled Weapon Creation!\n";
			return;
		}
	}

	while (true)
	{
		std::cout << "Weapon Ammo: ";
		std::cin >> maxAmmoString;

		if (TryParse(maxAmmoString, maxAmmo) == true)
		{
			ClearConsoleLines(1);
			std::cout << "Weapon Ammo: " << maxAmmo << "\n";
			break;
		}
		if (maxAmmoString == "q")
		{
			std::cout << "\nCancelled Weapon Creation!\n";
			return;
		}
	}

	weaponContainer.AddWeapon(CreateWeapon(weaponType, weaponName, damage, range, maxAmmo));
	std::cout << "Successfully added new weapon!\n";
}

void EditWeapon(WeaponContainer& weaponContainer)
{
	std::string response = "";

	system("cls");
	std::cout << "Weapon Name to edit: ";
	std::getline(std::cin >> std::ws, response);

	Weapon viewWeapon = weaponContainer.GetWeapon(response);

	if (viewWeapon.weaponType != Weapon::Invalid && viewWeapon.weaponType != Weapon::Count)
	{
		PrintWeaponInfo(viewWeapon);

		std::string statResponse = "";
		int intResponseValue = 0;

		std::cout << "Press q to cancel editing at any point (cancelling won't save any changes)\n\n";
		while (true)
		{
			std::cout << "What stat do you want to update (Damage, Range, Ammo): ";
			std::getline(std::cin >> std::ws, response);

			if (TryParse(response) == false)
			{
				if (response == "q")
				{
					std::cout << "\nCancelled Weapon Editing!\n";
					return;
				}

				ClearConsoleLines(3);
				continue;
			}
			else if (TryParse(response) == true)
			{
				if (response == "Damage")
				{
					while (true)
					{
						std::cout << "New Weapon Damage: ";
						std::cin >> statResponse;

						if (TryParse(statResponse, intResponseValue) == true)
						{
							viewWeapon.damage = intResponseValue;
							ClearConsoleLines(1);
							std::cout << "New Weapon Damage: " << intResponseValue << "\n";
							break;
						}

						if (statResponse == "q")
						{
							std::cout << "\nCancelled Weapon Editing!\n";
							return;
						}
					}
				}
				else if (response == "Range")
				{
					while (true)
					{
						std::cout << "New Weapon Range: ";
						std::cin >> statResponse;

						if (TryParse(statResponse, intResponseValue) == true)
						{
							viewWeapon.range = intResponseValue;
							ClearConsoleLines(1);
							std::cout << "New Weapon Range: " << intResponseValue << "\n";
							break;
						}
						if (statResponse == "q")
						{
							std::cout << "\nCancelled Weapon Editing!\n";
							return;
						}
					}
				}
				else if (response == "Ammo")
				{
					while (true)
					{
						std::cout << "New Weapon Ammo: ";
						std::cin >> statResponse;

						if (TryParse(statResponse, intResponseValue) == true)
						{
							viewWeapon.maxAmmo = intResponseValue;
							ClearConsoleLines(1);
							std::cout << "New Weapon Ammo: " << intResponseValue << "\n";
							break;
						}
						if (statResponse == "q")
						{
							std::cout << "\nCancelled Weapon Editing!\n";
							return;
						}
					}
				}
			}

			if (weaponContainer.UpdateWeapon(viewWeapon))
			{
				std::cout << "Successfully edited weapon!\n";
			}
			else
			{
				std::cout << "Something went wrong with editing!\n";
			}

			break;
		}
	}
	else
	{
		std::cout << "No weapon with that names exists!\n";
	}
}

void RemoveWeapon(WeaponContainer& weaponContainer)
{
	std::string response = "";

	system("cls");
	std::cout << "Weapon Name to remove: ";
	std::getline(std::cin >> std::ws, response);

	if (weaponContainer.RemoveWeapon(response) == true)
	{
		std::cout << "Successfully deleted weapon!\n";
	}
	else
	{
		std::cout << "Weapon with that name doesn't exist!\n";
	}
}


int main()
{
	WeaponContainer weaponContainer;
	weaponContainer.AddWeapon(CreateWeapon(Weapon::Sword, "Bronze Sword", 5, 1, 1));
	weaponContainer.AddWeapon(CreateWeapon(Weapon::Sword, "Iron Sword", 7, 1, 1));
	weaponContainer.AddWeapon(CreateWeapon(Weapon::Sword, "Steel Sword", 10, 1, 1));
	weaponContainer.AddWeapon(CreateWeapon(Weapon::Axe, "Bronze Axe", 5, 1, 1));
	weaponContainer.AddWeapon(CreateWeapon(Weapon::Axe, "Iron Axe", 7, 1, 1));
	weaponContainer.AddWeapon(CreateWeapon(Weapon::Axe, "Steel Axe", 10, 1, 1));
	weaponContainer.AddWeapon(CreateWeapon(Weapon::Spear, "Bronze Spear", 5, 3, 1));
	weaponContainer.AddWeapon(CreateWeapon(Weapon::Spear, "Iron Spear", 7, 3, 1));
	weaponContainer.AddWeapon(CreateWeapon(Weapon::Spear, "Steel Spear", 10, 3, 1));
	weaponContainer.AddWeapon(CreateWeapon(Weapon::Staff, "Amber Staff", 5, 5, 1));
	weaponContainer.AddWeapon(CreateWeapon(Weapon::Staff, "Emerald Staff", 7, 7, 1));
	weaponContainer.AddWeapon(CreateWeapon(Weapon::Staff, "Platinum Staff", 10, 10, 1));
	weaponContainer.AddWeapon(CreateWeapon(Weapon::Hammer, "Bronze Hammer", 5, 1, 1));
	weaponContainer.AddWeapon(CreateWeapon(Weapon::Hammer, "Iron Hammer", 7, 1, 1));
	weaponContainer.AddWeapon(CreateWeapon(Weapon::Hammer, "Steel Hammer", 10, 1, 1));
	weaponContainer.AddWeapon(CreateWeapon(Weapon::Bow, "Feather Bow", 5, 10, 10));
	weaponContainer.AddWeapon(CreateWeapon(Weapon::Bow, "Firm Bow", 7, 15, 15));
	weaponContainer.AddWeapon(CreateWeapon(Weapon::Bow, "Long Bow", 10, 30, 10));

	std::string response = "";
	bool running = true;
	while (running)
	{
		system("cls");
		std::cout << "Weapon Editor\n";
		std::cout << "Pick An Option:\n";
		std::cout << "[1] View All Weapons\n";
		std::cout << "[2] View All Weapons Of Type\n";
		std::cout << "[3] View Weapon\n";
		std::cout << "[4] Add Weapon\n";
		std::cout << "[5] Edit Weapon\n";
		std::cout << "[6] Remove Weapon\n";
		std::cout << "[q] Quit\n";

		std::cin >> response;

		if (response == "q")
		{
			running = false;
			continue;
		}

		if (response == "1")
		{
			ViewAllWeapons(weaponContainer);
		}
		else if (response == "2")
		{
			ViewWeaponsOfType(weaponContainer);
		}
		else if (response == "3")
		{
			ViewWeapon(weaponContainer);
		}
		else if (response == "4")
		{
			AddWeapon(weaponContainer);
		}
		else if (response == "5")
		{
			EditWeapon(weaponContainer);
		}
		else if (response == "6")
		{
			RemoveWeapon(weaponContainer);
		}

		system("pause");
	}
}


// Assignment 4
// The Weapon Editor
// Finish up the program
//  - Weapon should not need to be modified
//  - WeponContainer should not need to be updated, but has return values that can help handle errors
// Add 2-3 weapons manually for each type
// Ask the user to make a selection (view all weapons, view weapons of type, view weapon, add weapon, edit weapon, remove weapon)
// When user makes a selection, display should show the mode
// MODES:
//      - View All Weapons
//          - display all the weapons (use weaponContainer.Print())
//      - View All Weapons Of Type
//          - ask user for a weapon type
//          - display all the weapons for the specified type (use weaponContainer.Print(weaponType))
//      - View Weapon
//          - ask user for a weapon name
//          - find the weapon and display the info
//          - if not found, let user know it was not found
//      - Add Weapon
//          - ask user for a weapon name (it must be unique, no other weapon can have this name)
//          - ask user for each other weapon stat (weapon type, damage, range, maxAmmo, starter)
//          - ensure all inputs are valid
//          - display if the weapon was added successfully
//      - Edit Weapon
//          - ask user for the weapon name
//          - if found, ask what value to update 
//          - get the value from the player, apply to the weapon data, add it back to the weapon container
//          - ensure all inputs are valid
//          - display if the edit was made successfully
//      - Remove Weapon
//          - ask user for the weapon name
//          - if the weapon name is found, remove the weapon
//          - display if the weapon was removed successfully
// When player inputs information, ensure the information is valid (int should be an int, float should be a float, bool should be a bool, string should be a string)
// if the input is invalid, let the user know the information was incorrect and repeat the request until the expected information is inputed
//      - damage must be more than 0 and less than 100
//      - range must be more than 0 and less than 7
//      - name can't be the same as another weapon
//      - there can only be one starter for each weapon type --------------------------IGNORE

//Mark Breakdown :
//Application builds and runs :               50
//Application functions as described :        20
//Build includes handles errors each state :  20
//Coding standards, minor errors :            10