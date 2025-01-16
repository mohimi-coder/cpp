/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:33:51 by mohimi            #+#    #+#             */
/*   Updated: 2024/12/06 14:33:51 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << this->_name << yellow << ": BraiiiiiiinnnzzzZ..." << pos << std::endl;
}

Zombie::~Zombie()
{
    std::cout << color << "ZombieHorde Destroyed: " << pos << this->_name << std::endl;
}
Zombie::Zombie()
{
}
void Zombie::set_name(std::string name)
{
    this->_name = name;
}