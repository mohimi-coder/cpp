/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:34:20 by mohimi            #+#    #+#             */
/*   Updated: 2024/12/06 14:34:20 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define color "\001\033[1;36m\002"
#define pos "\001\033[0;0m\002"
#define yellow "\001\033[1;33m\002"
#define grey "\001\033[1;30m\002"

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;
    std::cout << color << "The memory address of the string variable: " << &string << pos << std::endl;
    std::cout << color << "The memory address held by stringPTR: " << stringPTR << pos << std::endl;
    std::cout << color << "The memory address held by stringREF: " << &stringREF<< pos << std::endl;

    std::cout << grey << "-----------------------------------------------------" << pos << std::endl;

    std::cout << yellow << "The value of the string variable: " << string << pos << std::endl;
    std::cout << yellow << "The value pointed to by stringPTR: " << *stringPTR << pos << std::endl;
    std::cout << yellow << "The value pointed to by stringREF: " << stringREF<< pos << std::endl;
    return 0;
}