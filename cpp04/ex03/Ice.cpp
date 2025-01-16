/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:52:03 by mohimi            #+#    #+#             */
/*   Updated: 2025/01/10 21:20:41 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice &other) : AMateria("ice")
{
    *this = other;
}

Ice &Ice::operator=(const Ice &other)
{
    if (this != &other)
        this->_type = "ice";
    return *this;
}

Ice::~Ice()
{
}

void Ice::use(ICharacter &target) 
{
	std::cout << CYAN << "* shoots an ice bolt at " << target.getName() << " *" << RESET<< std::endl;
}

AMateria *Ice::clone() const
{ 
    return new Ice(*this); 
}
