/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 19:45:24 by mohimi            #+#    #+#             */
/*   Updated: 2024/12/30 15:16:53 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() 
{
	std::cout << gold <<"-------- CONSTRUCTORS -------" << pos << std::endl;
	ClapTrap mohimi("mohimi");
	FragTrap robot("Robot");
	FragTrap carlo;
	FragTrap publiclone(robot);

	std::cout << gold << std::endl << "------- VALID ACTIONS -------" << pos << std::endl;
	mohimi.attack("Robot");
	robot.attack("mohimi");
	robot.takeDamage(2);
	robot.beRepaired(1);
	robot.highFivesGuys();

	std::cout << std::endl << gold << "----------- INVALID ACTIONS -------" << pos << std::endl;
	robot.takeDamage(100);
	robot.attack("mohimi");
	robot.takeDamage(2);
	robot.beRepaired(2);
	robot.highFivesGuys();

	for (int i = 0; i < 101; i++) 
	{
		publiclone.attack("mohimi");
	}

	std::cout << std::endl << gold << "-------- DESTRUCTORS --------" << pos << std::endl;
	return 0;
}