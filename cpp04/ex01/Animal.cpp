/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:33:36 by mohimi            #+#    #+#             */
/*   Updated: 2025/01/08 13:30:07 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("unknown_type")
{
    std::cout << YELLOW << "Default Animal constructer called!" << RESET << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << YELLOW << "Animal: " << _type << " called!" << std::endl;
}

Animal::Animal(const Animal &other)
{
    std::cout << YELLOW << "Animal: " << _type << " coppied" << RESET << std::endl;
    *this = other;
}

Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
        this->_type = other._type;
    std::cout << YELLOW << "Animal: " << _type << " assigned." << RESET << std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout << YELLOW << "Animal: " << _type << " ,Destroyed" << RESET << std::endl;
}

std::string Animal::getType() const
{
    return _type;
}

void Animal::makeSound() const
{
    std::cout << CYAN << "Animal makes a sounds!" << std::endl;
}