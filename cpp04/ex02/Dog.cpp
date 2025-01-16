/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:14:38 by mohimi            #+#    #+#             */
/*   Updated: 2025/01/08 20:31:53 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    this->_type = "Dog";
    std::cout << GREEN << "Default Dog constructor called!" << RESET << std::endl;
    brain = new Brain("i'm Dog!");
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << GREEN << "Dog copy constructor called!" << RESET << std::endl;
    brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
		Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
	std::cout << GREEN << "Dog Copy assignment operator called" << RESET << std::endl;
	return *this;
}

Dog::~Dog()
{
    std::cout << GREEN << "Dog Destructor called" << RESET << std::endl;
    delete brain;
}


void Dog::makeSound() const
{
    std::cout << GREEN << "Woof Woof" << RESET << std::endl;
}