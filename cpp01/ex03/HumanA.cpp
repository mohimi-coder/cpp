/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:34:40 by mohimi            #+#    #+#             */
/*   Updated: 2024/12/06 14:34:40 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA()
{
    std::cout << grey << "class HumanA is destroyed!" << pos << std::endl;
}

void HumanA::attack() const
{
    if(_weapon.getType().empty())
    {
        std::cout << _name << grey << " tried to attack without a weapon HAHAHA...!" << pos << std::endl;
        return;
    }
    std::cout << _name << color << " attacks with his " << _weapon.getType() << pos << std::endl;
}
