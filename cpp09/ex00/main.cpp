/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:24:36 by mohimi            #+#    #+#             */
/*   Updated: 2025/02/21 14:45:25 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
        {
            std::cerr << RED << "Error: could not open file." << pos  << std::endl;
            return 1;
        }
        BitcoinExchange exchange;
        exchange.loadDatabase(av[1]);
        return 0;
    }
    catch(const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
