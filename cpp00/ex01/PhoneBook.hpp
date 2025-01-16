/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:33:11 by mohimi            #+#    #+#             */
/*   Updated: 2024/12/06 10:33:11 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"
#include<string>


#define color "\001\033[1;36m\002"
#define pos "\001\033[0;0m\002"
#define yellow "\001\033[1;33m\002"
#define grey "\001\033[1;30m\002"
#define lg "\001\033[92m\002"
#define b_italic "\001\033[1;3m\002"
#define gold "\001\033[38;5;220m\002" 
#define dark_blue "\001\033[34m\002"
#define teal "\001\033[38;5;30m\002"
#define violet "\001\033[38;5;128m\002"
#define b_ora "\001\033[1;38;5;208m\002"

class PhoneBook
{
    private:
        Contact contacts[8];
        int lenght;
        int index;
    public:
        PhoneBook();
        ~PhoneBook();
        int     get_len();
        void    add_contact();
        void    display_contact(int i);
        void    display_phonebook();
};
#endif