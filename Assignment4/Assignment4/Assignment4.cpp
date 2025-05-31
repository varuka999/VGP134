// Assignment4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "WeaponContainer.h"

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

}

void AddWeapon(WeaponContainer& weaponContainer)
{

}

void EditWeapon(WeaponContainer& weaponContainer)
{

}

void RemoveWeapon(WeaponContainer& weaponContainer)
{

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

int main()
{
    WeaponContainer weaponContainer;

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
//      - there can only be one starter for each weapon type

//Mark Breakdown :
//Application builds and runs :               50
//Application functions as described :        20
//Build includes handles errors each state :  20
//Coding standards, minor errors :            10