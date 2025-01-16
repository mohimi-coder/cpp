/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:41:55 by mohimi            #+#    #+#             */
/*   Updated: 2024/12/31 16:14:49 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

#include <iostream>
#include <string>

class DiamondTrap: public FragTrap, public ScavTrap
{
    public:
        DiamondTrap();
        DiamondTrap(const DiamondTrap &other);
        ~DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap& operator=(const DiamondTrap& other);
        void whoAmI();
    private:
        std::string _name;
};

#endif