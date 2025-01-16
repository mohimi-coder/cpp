/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:36:35 by mohimi            #+#    #+#             */
/*   Updated: 2025/01/08 17:37:39 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    this->_type = "Cat";
    std::cout << CYAN << "Default Cat constructor called!" << RESET << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << CYAN << "Cat copy constructor called!" << RESET << std::endl;
    *this = other;
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
		Animal::operator=(other);
	std::cout << CYAN << "Cat Copy assignment operator called" << RESET << std::endl;
	return *this;
}

Cat::~Cat()
{
    std::cout << CYAN << "Cat Destructor called" << RESET << std::endl;
}

void Cat::makeSound() const
{
    std::cout << CYAN << "Meow Meow" << RESET << std::endl;
}