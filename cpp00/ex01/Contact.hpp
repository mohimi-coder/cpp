/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:32:34 by mohimi            #+#    #+#             */
/*   Updated: 2024/12/06 10:32:34 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
    private:
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string secret;
        std::string number;
    public:
        std::string get_firstname();
        std::string get_lastname();
        std::string get_nickname();
        std::string get_secret();
        std::string get_number();
        void        set_lastname(std::string last);
        void        set_firstname(std::string name);
        void        set_nickname(std::string nick);
        void        set_secret(std::string secret);
        void        set_number(std::string number);
};

#endif