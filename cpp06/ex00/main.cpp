/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:13:12 by mohimi            #+#    #+#             */
/*   Updated: 2025/02/03 16:49:09 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverte.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << RED "Error: wrong number of arguments" RESET << std::endl;
        return (1);
    }
    std::string str = av[1];
    ScalarConverte::convert(str);
    return (0);
}