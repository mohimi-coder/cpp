/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:32:25 by mohimi            #+#    #+#             */
/*   Updated: 2024/12/06 10:32:25 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"

std::string Contact::get_firstname()
{
    return(firstname);
}
std::string Contact::get_lastname()
{
    return(lastname);
}
std::string Contact::get_nickname()
{
    return(nickname);
}
std::string Contact::get_number()
{
    return(number);
}
std::string Contact::get_secret()
{
    return(secret);
}
void Contact::set_firstname(std::string first)
{
    firstname = first;
}
void Contact::set_lastname(std::string last)
{
    lastname = last;
}
void Contact::set_nickname(std::string nick)
{
    nickname = nick;
}
void Contact::set_number(std::string number)
{
    this->number = number;
}
void Contact::set_secret(std::string secret)
{
    this->secret = secret;
}
