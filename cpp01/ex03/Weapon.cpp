/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:59:04 by mohimi            #+#    #+#             */
/*   Updated: 2024/12/16 09:59:04 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string n_type) : type(n_type)
{
}
Weapon::~Weapon()
{
    std::cout << grey << "class Weapon is destroyed!" << pos << std::endl;
}
const std::string &Weapon::getType() const
{
    return type;
}
void Weapon::setType(const std::string new_t)
{
    type = new_t;
}