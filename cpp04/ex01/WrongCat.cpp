/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:59:50 by mohimi            #+#    #+#             */
/*   Updated: 2025/01/05 16:55:24 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
WrongCat::WrongCat()
{
    _type = "WrongCat";
    std::cout << RED << "Default WrongCat constructor called!" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << RED << "WrongCat copy constructor called!" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    if (this != &other)
		WrongAnimal::operator=(other);
	std::cout << RED << "WrongCat Copy assignment operator called" << RESET << std::endl;
	return *this;
}

WrongCat::~WrongCat()
{
    std::cout << RED << "WrongCat Destructor called" << RESET << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << RED << "Mow" << RESET << std::endl;
}