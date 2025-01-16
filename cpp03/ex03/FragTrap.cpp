/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:20:06 by mohimi            #+#    #+#             */
/*   Updated: 2025/01/06 19:14:25 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() 
{
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
    std::cout << color << "FragTrap: Default Constructor called" << pos << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
    std::cout << color << "FragTrap: " << _name << " Constructor called" << pos << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
   std::cout << color << "FragTrap: " << _name << " Copy Constructor called" << pos << std::endl;
}

FragTrap::~FragTrap() 
{
    std::cout << color << "FragTrap: " << _name << " Destructor called" << pos << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) 
{
    std::cout << color << "FragTrap: " << _name << " Assignment Operator called" << pos << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

void FragTrap::highFivesGuys(void)
{
  if (energy_points == 0)
    {
        std::cout << color << "FragTrap: " << _name << " there is no energy left" << pos << std::endl;
        return;
    }
    else if (hit_points == 0)
    {
        std::cout << color << "FragTrap: " << _name << " there is no enough hit_points" << pos << std::endl;
        return;
    }
    std::cout << color << "FragTrap: " << _name <<  " has entered into highFivesGuys" << pos << std::endl;
    energy_points--;
}