/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 19:45:31 by mohimi            #+#    #+#             */
/*   Updated: 2025/01/06 19:22:09 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap: " << _name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap: " << _name << " cppied" << std::endl;
    *this = other;
}

ClapTrap::~ClapTrap()
{
     std::cout << "ClapTrap: " << _name << " Destroyed!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->hit_points = other.hit_points;
        this->energy_points = other.energy_points;
        this->attack_damage = other.attack_damage;
    }
    std::cout << "ClapTrap: " << _name << " assigned." << std::endl;
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (energy_points > 0 && hit_points > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks "<< target << ", dealing " << attack_damage << " damage!" << std::endl;
        energy_points--;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " Cant attack because ";
        if (energy_points == 0)
            std::cout << "it has no energy left." << std::endl;
        else
            std::cout << "it has no hit points left." << std::endl;
    }
    
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(hit_points > amount)
        hit_points -= amount;
    else
        hit_points = 0;
    std::cout << "ClapTrap " << _name << "  was damaged, Hit points: "  << hit_points << " , Energy points: " << energy_points << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
     if (energy_points > 0)
    {
        energy_points--;
        hit_points += amount;
        std::cout << "ClapTrap " << _name << "  was repaired, Hit points : " << hit_points << " , Energy points : " << energy_points << std::endl;
    }
    else 
        std::cout << "\033[31mClapTrap " << _name << " is not able to repair itself, because he doesn't have enough energy points.\033[0m" << std::endl;
}
