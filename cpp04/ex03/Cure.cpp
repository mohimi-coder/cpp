/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:15:04 by mohimi            #+#    #+#             */
/*   Updated: 2025/01/15 15:47:35 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure &other) : AMateria("cure")
{
    *this = other;
}

Cure &Cure::operator=(const Cure &other)
{
    if (this != &other)
        this->_type = "cure";
    return *this;
}

Cure::~Cure()
{
}

void Cure::use(ICharacter &target) 
{
	std::cout << gold << "* heals " << target.getName() << "'s wounds *" << RESET <<  std::endl;
}

AMateria *Cure::clone() const
{ 
    return new Cure(*this); 
}
