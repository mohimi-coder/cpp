/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:46:46 by mohimi            #+#    #+#             */
/*   Updated: 2025/01/21 18:33:46 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


void Harl::debug( void )
{
	std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
void Harl::info( void )
{
	std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning( void )
{
	std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error( void )
{
	std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
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

void Harl::complain(std::string level)
{
    void (Harl::*funcPTR[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
     std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
     for(int i = 0; i < 4; i++)
     {
        if (level == levels[i])
        {
            (this->*funcPTR[i])();
            return;
        }
     }
     std::cout << "Unknown level: " << level << std::endl;
}