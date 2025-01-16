/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:34:57 by mohimi            #+#    #+#             */
/*   Updated: 2024/12/06 14:34:57 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::~HumanB()
{
}
HumanB::HumanB(const std::string &name) : _name(name)
{
    this->_weapon = NULL;
}
void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}

void HumanB::attack() const
{
     if(!_weapon || _weapon->getType().empty())
    {
        std::cout << _name << grey << " has no weapon to attack with!" << pos << std::endl;
    }
    else
        std::cout << _name << yellow << " attacks with his " << _weapon->getType() << pos << std::endl;
}

