/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:08:57 by mohimi            #+#    #+#             */
/*   Updated: 2025/01/06 19:12:12 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() 
{
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
    std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
    std::cout << "ScavTrap: " << _name << " Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
   std::cout << "ScavTrap" << _name << " Copy Constructor called" << std::endl;
}

ScavTrap::~ScavTrap() 
{
    std::cout << "ScavTrap: " << _name << " Destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) 
{
    std::cout << "ScavTrap: " << _name << " Assignment Operator called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

void ScavTrap::guardGate()
{
    if (energy_points == 0)
    {
        std::cout << "ScaTrap: " << _name << " there is no energy left" << std::endl;
        return;
    }
    else if (hit_points == 0)
    {
        std::cout << "ScaTrap: " << _name << " there is no enough hit_points" << std::endl;
        return;
    }
    std::cout << "ScavTrap: " << _name <<  " has entered into guardGate" << std::endl;
    energy_points--;
}

void ScavTrap::attack(const std::string& target)
{
    if (energy_points == 0)
    {
        std::cout << "ScaTrap: " << _name << " there is no energy left" << std::endl;
        return;
    }
    else if (hit_points == 0)
    {
        std::cout << "ScaTrap: " << _name << " there is not enough hit_points" << std::endl;
        return;
    }
    std::cout << "ScavTrap: " << _name <<  " atacks "  << target << " ,causing " << attack_damage << std::endl;
    energy_points--;
}