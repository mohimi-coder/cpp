/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:14:38 by mohimi            #+#    #+#             */
/*   Updated: 2025/01/08 17:38:00 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    this->_type = "Dog";
    std::cout << GREEN << "Default Dog constructor called!" << RESET << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << GREEN << "Dog copy constructor called!" << RESET << std::endl;
    *this = other;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
		Animal::operator=(other);
	std::cout << GREEN << "Dog Copy assignment operator called" << RESET << std::endl;
	return *this;
}

Dog::~Dog()
{
    std::cout << GREEN << "Dog Destructor called" << RESET << std::endl;
}

void Dog::makeSound() const
{
    std::cout << GREEN << "Woof Woof" << RESET << std::endl;
}