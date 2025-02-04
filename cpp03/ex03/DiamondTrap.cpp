/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:42:00 by mohimi            #+#    #+#             */
/*   Updated: 2025/01/31 12:13:51 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
     std::cout << dark_blue << "DiamondTrap: Default constructor called" << pos << std::endl;
     this->hit_points = FragTrap::hit_points;
     this->energy_points = ScavTrap::energy_points;
     this->attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name) 
{
     std::cout << "DiamondTrap " << name << " created" << std::endl;
     this->hit_points = FragTrap::hit_points;
     this->energy_points = ScavTrap::energy_points;
     this->attack_damage = FragTrap::attack_damage;
}

DiamondTrap::~DiamondTrap()
{
     std::cout << "DiamondTrap: " << _name << " Destroyed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name) 
{
    std::cout << "DiamondTrap: " << _name << "coppied" << std::endl;
    *this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        this->_name = other._name;
    }
    std::cout << "DiamondTrap: " << _name << " assigned." << std::endl;
    return *this;
}

void DiamondTrap::whoAmI()
{
     std::cout << "ClapTrap: " << ClapTrap::_name << " ,DiamondTrap: " << DiamondTrap::_name << std::endl;
}