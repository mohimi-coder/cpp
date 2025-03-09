/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:32:57 by mohimi            #+#    #+#             */
/*   Updated: 2025/02/22 15:27:39 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
        {
            std::cerr << "Error: invalid number of arguments." << std::endl;
            return 1;
        }
        RPN rpn(av[1]);
        rpn.fixInput();
        return 0;
    }
    catch(const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}