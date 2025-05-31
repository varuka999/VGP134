#include "WeaponContainer.h"
#include <iostream>

std::string GetWeaponTypeName(Weapon::WeaponType weaponType)
{
    switch (weaponType)
    {
    case Weapon::Sword:     return "Sword";
    case Weapon::Bow:       return "Bow";
    case Weapon::Staff:     return "Staff";
    case Weapon::Spear:     return "Spear";
    case Weapon::Hammer:    return "Hammer";
    case Weapon::Axe:       return "Axe";
    default:
        break;
    }
    return "";
}


bool WeaponContainer::HasWeaponName(const std::string& name)
{
    for (auto& weapons : mWeaponCollection)
    {
        auto iter = std::find_if(weapons.second.begin(), weapons.second.end(), FindByNameFunctor(name));
        if (iter != weapons.second.end())
        {
            return true;
        }
    }
    return false;
}

bool WeaponContainer::AddWeapon(const Weapon& weapon)
{
    for (auto& weapons : mWeaponCollection)
    {
        auto iter = std::find_if(weapons.second.begin(), weapons.second.end(), FindByNameFunctor(weapon.name));
        if (iter != weapons.second.end())
        {
            return false;
        }
    }

    mWeaponCollection[weapon.weaponType].push_back(weapon);
    return true;
}

bool WeaponContainer::RemoveWeapon(const std::string& name)
{
    for (auto& weapons : mWeaponCollection)
    {
        auto iter = std::find_if(weapons.second.begin(), weapons.second.end(), FindByNameFunctor(name));
        if (iter != weapons.second.end())
        {
            weapons.second.erase(iter);
            return true;
        }
    }

    return false;
}

Weapon WeaponContainer::GetWeapon(const std::string& name)
{
    for (auto& weapons : mWeaponCollection)
    {
        auto iter = std::find_if(weapons.second.begin(), weapons.second.end(), FindByNameFunctor(name));
        if (iter != weapons.second.end())
        {
            return (*iter);
        }
    }

    return Weapon();
}

bool WeaponContainer::UpdateWeapon(const Weapon& data)
{
    for (auto& weapons : mWeaponCollection)
    {
        auto iter = std::find_if(weapons.second.begin(), weapons.second.end(), FindByNameFunctor(data.name));
        if (iter != weapons.second.end())
        {
            (*iter) = data;
            return true;
        }
    }

    return false;
}

void WeaponContainer::Print(Weapon::WeaponType weaponType)
{
    int maxPerRow = 4;
    for (int i = Weapon::Invalid + 1; i < Weapon::Count; ++i)
    {
        if (weaponType == Weapon::Invalid || i == weaponType)
        {
            Weapon::WeaponType wt = (Weapon::WeaponType)i;
            std::cout << GetWeaponTypeName(wt) << ":\n";
            if (mWeaponCollection.find(wt) != mWeaponCollection.end())
            {
                auto& weapons = mWeaponCollection[wt];
                for (int row = 0; row < weapons.size(); row += maxPerRow)
                {
                    int maxItems = std::min(row + maxPerRow, (int)(weapons.size()));
                    for (int w = row; w < maxItems; ++w)
                    {
                        if (weapons[w].name.size() < 7) // can adjust here to align if needed
                        {
                            std::cout << weapons[w].name << "\t\t|\t";
                        }
                        else
                        {
                            std::cout << weapons[w].name << "\t|\t";
                        }
                    }
                    std::cout << "\n";
                    for (int w = row; w < maxItems; ++w)
                    {
                        std::cout << "Damage: " << weapons[w].damage << "\t|\t";
                    }
                    std::cout << "\n";
                    for (int w = row; w < maxItems; ++w)
                    {
                        std::cout << "Range: " << weapons[w].range << "\t|\t";
                    }
                    std::cout << "\n";
                    for (int w = row; w < maxItems; ++w)
                    {
                        std::cout << "MaxAmmo: " << weapons[w].maxAmmo << "\t|\t";
                    }
                    std::cout << "\n";
                    for (int w = row; w < maxItems; ++w)
                    {
                        std::cout << "Starter: " << weapons[w].starter << "\t|\t";
                    }
                    std::cout << "\n\n";
                }
                std::cout << "\n";
            }
            else
            {
                std::cout << "No weapons for this type\n\n\n";
            }
        }
    }
}
