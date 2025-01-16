/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:33:18 by mohimi            #+#    #+#             */
/*   Updated: 2024/12/06 14:33:18 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << this->_name << yellow << ": BraiiiiiiinnnzzzZ..." << pos << std::endl;
}

Zombie::~Zombie()
{
    std::cout << color << "Zombie Destroyed: " << this->_name << pos << std::endl;
}
Zombie::Zombie(std::string name) : _name(name)
{
}