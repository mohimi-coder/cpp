/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:40:47 by mohimi            #+#    #+#             */
/*   Updated: 2025/01/15 12:03:55 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() 
{

	{
		const Animal	*j = new Dog();
		const Animal	*i = new Cat();
		j->makeSound();
		i->makeSound();

		delete j;
		delete i;
	}

	std::cout << std::endl;
	{
		Animal	*i = new Cat();
		Animal	*j = new Cat();

		*i = *j;
		i->makeSound();
		j->makeSound();

		delete i;
		delete j;
	}

}