/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:35:18 by mohimi            #+#    #+#             */
/*   Updated: 2025/01/15 12:29:05 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
    for (int i = 0; i <= 3; i++)
    {
        _inventory[i] = NULL;
        _temp[i] = NULL;
    }
}

Character::Character(std::string const &name) : _name(name)
{
    for (int i = 0; i <= 3; i++)
    {
        _inventory[i] = NULL;
        _temp[i] = NULL;
    }
}

Character::~Character()
{
    for (int i = 0; i <= 3; i++)
    {
        if (_inventory[i] != NULL)
        {
            delete _inventory[i];
            _inventory[i] = NULL;
        }
        if (_temp[i] != NULL)
        {
            delete _temp[i];
            _temp[i] = NULL;
        }
    }
}

Character::Character(const Character &other) : _name(other._name)
{
    for (int i = 0; i <= 3; i++)
        _inventory[i] = NULL;
    for (int i = 0; i <= 3; i++)
        _temp[i] = NULL;
    *this = other;
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        for (int i = 0; i <= 3; i++)
        {
            if (_inventory[i] != NULL)
            {
                delete _inventory[i];
                _inventory[i] = NULL;
            }
            if (_temp[i] != NULL)
            {
                delete _temp[i];
                _temp[i] = NULL;
            }
        }
        for (int i = 0; i <= 3; i++)
        {
            if (other._inventory[i] != NULL)
                _inventory[i] = other._inventory[i]->clone();
        }
    }
    return *this;
}

std::string const &Character::getName() const
{
    return _name;
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i <= 3; i++)
    {
        if (_temp[i] != NULL)
        {
            delete _temp[i];
            _temp[i] = NULL;
        }
    }
    for (int i = 0; i <= 3; i++)
    {
        if (_inventory[i] == m)
            return;
    }
    for (int i = 0; i <= 3; i++)
    {
        if (_inventory[i] == NULL)
        {
            _inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx <= 3)
    {
        if (_temp[idx] == NULL)
            _temp[idx] = _inventory[idx];
        _inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx <= 3 && _inventory[idx])
        _inventory[idx]->use(target);
}
