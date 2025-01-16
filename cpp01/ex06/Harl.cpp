/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:08:26 by mohimi            #+#    #+#             */
/*   Updated: 2024/12/11 13:28:49 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug() 
{
	std::cout << b_ora << "[ DEBUG ]" << res << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl;
}

void Harl::info() 
{
	std::cout << b_ora << "[ INFO ]" << res << std::endl;
    std::cout << "cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning() 
{
	std::cout << b_ora << "[ WARNING ]" << res << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error() 
{
	std::cout << b_ora << "[ ERROR ]" << res << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

Harl::Harl()
{
	std::cout << color << "+----------+----------+----------+----------+" << res << std::endl;
    std::cout << violet<< "|           HARL CREATED: WELCOME           |" << res << std::endl;
    std::cout << color << "+----------+----------+----------+----------+" << res << std::endl; 
}
Harl::~Harl()
{
	std::cout << color << "+----------+----------+----------+----------+" << res << std::endl;
    std::cout << violet<< "|           HARL DESTROYED GOOD BYE!        |" << res << std::endl;
    std::cout << color << "+----------+----------+----------+----------+" << res << std::endl; 
}
void Harl::harl_filter( std::string level )
{
	int index = -1;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for(int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			index = i;
			break;
		}
	}
	switch (index)
	{
	case 0:
		debug();
	case 1:
		info();
	case 2:
		warning();
	case 3:
		error();
		break;
	
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}

}