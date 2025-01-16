/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:30:36 by mohimi            #+#    #+#             */
/*   Updated: 2025/01/01 10:31:24 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>
static int if_isonly_space(std::string str)
{
    for(int i = 0; str[i]; i++)
    {
        if(str[i] != ' ')
            return 0;
    }
    return 1;
}

static int non_printables(std::string str)
{
    for(int i = 0; str[i]; i++)
    {
        if(str[i] < 32 || str[i] > 126)
            return 0;
    }
    return 1;
}

static int check_num(std::string number)
{
    for(int i = 0; number[i]; i++)
    {
        if(number[i] == ' ')
        {
            i++;
            continue;
        }
        if(number[i] < '0' || number[i] > '9')
            return 0;
    }
    return 1;
}

static int string_check(std::string str)
{
    for(int i = 0; str[i]; i++)
    {
        if(str[i] == ' ')
        {
            i++;
            continue;
        }
        if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
    }
    return 1;
}

static void name_print(std::string str)
{
    unsigned int i = 0;
    if(str.length() > 10)
    {
        std::cout << str.substr(0, 9);
        std::cout << ".";
    }
    else
    {
        i = 0;
        while(i++ < 10 - str.length())
            std::cout << " ";
        std::cout << str;
    } 
}

std::string inputs_string(std::string str)
{
    std::string inputs;

    while(inputs.empty() || if_isonly_space(inputs) || !string_check(inputs))
    {
        std::cout << violet << str << pos;
        std::getline(std::cin, inputs);
        if(std::cin.eof())
        {
            std::cout << color<< "\nyou are pressed ^D. Exiting PhoneBook!" << pos << std::endl;
            exit(1);
        }
    }
    return(inputs);
}

std::string inputs_number(std::string str)
{
    std::string inputs;

    while(inputs.empty() || if_isonly_space(inputs) || !check_num(inputs))
    {
        std::cout << violet << str << pos;
        std::getline(std::cin, inputs);
        if(std::cin.eof())
        {
            std::cout << color<< "\nyou are pressed ^D. Exiting PhoneBook!" << pos << std::endl;
            exit(1);
        }
    }
    return(inputs);
}

std::string inputs(std::string str)
{
    std::string inputs;

    while(inputs.empty() || !non_printables(inputs) || if_isonly_space(inputs))
    {
        std::cout << violet << str << pos;
        std::getline(std::cin, inputs);
        if(std::cin.eof())
        {
            std::cout << color<< "\nyou are pressed ^D. Exiting PhoneBook!" << pos << std::endl;
            exit(1);
        }
    }
    return(inputs);
}

PhoneBook::PhoneBook() : lenght(0), index(0)
{
}

PhoneBook::~PhoneBook()
{
    std::cout << "\001\033[1;33m\002PhoneBook destroyed Good bye!\001\033[0;0m\002" << std::endl;
}

int PhoneBook::get_len()
{
    return(lenght);
}

void PhoneBook::add_contact()
{
    contacts[index].set_firstname(inputs_string("What is your First Name: "));
    contacts[index].set_lastname(inputs_string("What is your Last Name: "));
    contacts[index].set_nickname(inputs("What is your Nick Name: "));
    contacts[index].set_number(inputs_number("What is your Phone Number: "));
    contacts[index].set_secret(inputs("What is your Dark Secret: "));
    std::cout << "\001\033[1;34m\002Contact added Successfully!\001\033[0;0m\002" << std::endl; 
    index = (index + 1) % 8;
    if(lenght < 8)
        lenght++;
}

void PhoneBook::display_contact(int i)
{
    std::cout << color << "+----------+----------+----------+----------+" << pos << std::endl;
    std::cout << teal <<  "|  Contact information for specified index  |" << pos << std::endl;
    std::cout << color << "+----------+----------+----------+----------+" << pos << std::endl;

    std::cout << gold b_italic << "Firstname: " << pos << contacts[i].get_firstname() << std::endl;
    std::cout << gold b_italic << "Lastname: " << pos << contacts[i].get_lastname() << std::endl;
    std::cout << gold b_italic << "Nickname: " << pos << contacts[i].get_nickname() << std::endl;
    std::cout << gold b_italic << "Number: " << pos << contacts[i].get_number() << std::endl;
    std::cout << gold b_italic << "Darkest Secret: " << pos << contacts[i].get_secret() << std::endl;
}
void PhoneBook::display_phonebook()
{
    std::cout << color << "+----------+----------+----------+----------+" << pos << std::endl;
    std::cout << teal  << "|   index  |first name|last name | nick name|" << pos << std::endl;
    std::cout << color << "+----------+----------+----------+----------+" << pos << std::endl;
    for(int i = 0; i < lenght; i++)
    {
        std::cout << color << "|         " << pos;
        std::cout << i;
        std::cout << color << "|" << pos;
        name_print(contacts[i].get_firstname());
        std::cout << color << "|" << pos;
        name_print(contacts[i].get_lastname());
        std::cout << color << "|" << pos;
        name_print(contacts[i].get_nickname());
        std::cout << color << "|" << pos << std::endl;
    }
    std::cout << color << "+----------+----------+----------+----------+" << pos << std::endl;
}