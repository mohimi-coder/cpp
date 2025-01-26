/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:20:11 by mohimi            #+#    #+#             */
/*   Updated: 2025/01/20 21:42:29 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#define color "\001\033[1;36m\002"
#define res "\001\033[0;0m\002"
#define b_ora "\001\033[1;38;5;208m\002"
#define violet "\001\033[38;5;128m\002"

int main() 
{
    Harl harl;

    std::cout << b_ora << "Testing DEBUG level:" << res << std::endl;
    harl.complain("DEBUG");

    std::cout << b_ora << "\nTesting INFO level:" << res << std::endl;
    harl.complain("INFO");

    std::cout << b_ora << "\nTesting WARNING level:" << res << std::endl;
    harl.complain("WARNING");

    std::cout << b_ora << "\nTesting ERROR level:" << res << std::endl;
    harl.complain("ERROR");

    return 0;
}
