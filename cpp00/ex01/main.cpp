/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:32:42 by mohimi            #+#    #+#             */
/*   Updated: 2024/12/06 10:32:42 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook notebook;
    
    std::string str;
    std::string idx_input;
    while(1)
    {
        std::cout << color << "+----------+----------+----------+----------+" << pos << std::endl;
        std::cout << teal  << "| Valid Commands : 'ADD' 'SEARCH' or 'EXIT' |" << pos << std::endl;
        std::cout << color << "+----------+----------+----------+----------+" << pos << std::endl;  
        std::getline(std::cin, str);
        if (std::cin.eof())
        {
            std::cout << gold << "you are pressed ^D. Exiting PhoneBook!" << pos << std::endl;
            break;
        }
        if(!str.compare("ADD"))
        {
            std::cout << "\001\033[1;32m\002\nEnter your contact information\001\033[0;0m\002" << std::endl;
            notebook.add_contact();
        } 
        else if(!str.compare("SEARCH"))
        {
            notebook.display_phonebook();
            std::cout << b_ora << "\nenter index: " << pos;
            std::getline(std::cin, idx_input);
            if (std::cin.fail() || idx_input.empty() || idx_input.length() != 1 || !std::isdigit(idx_input.at(0))) 
            {
                std::cout << "\001\033[1;31m\002Invalid Index!\001\033[0;0m\002" << std::endl;
                continue;
            }
            int idx = idx_input.at(0) - 48;
            if(idx >= notebook.get_len())
            {
                std::cout << "\001\033[1;31m\002Invalid Index!\001\033[0;0m\002" << std::endl;
                std::cin.clear();
                continue;
            }
            notebook.display_contact(idx);
            std::cin.clear();
            continue;
        }
        else if (!str.compare("EXIT"))
            break;
        else 
            std::cout << "\001\033[1;31m\002Invalid command try again!\001\033[0;0m\002" << std::endl;
    }
}
