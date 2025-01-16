/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:40:47 by mohimi            #+#    #+#             */
/*   Updated: 2025/01/15 16:08:22 by mohimi           ###   ########.fr       */
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

		delete j;
		delete i;
	}

	std::cout << std::endl;
	{
		Animal	*i = new Cat();
		Animal	*j = new Cat();

		*i = *j;

		delete i;
		delete j;
	}

	std::cout << std::endl;

	Animal	*animals[4];

	for (int i = 0; i < 4; i++) 
    {
		std::cout << "============== " "TESTS" " ===============" << std::endl;
		if (i < 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	std::cout << std::endl;

	for (int i = 0; i < 4; i++) 
    {
		std::cout << "============= " "ANIMALS" " =============" << std::endl;
		delete animals[i];
	}
	return 0;
}