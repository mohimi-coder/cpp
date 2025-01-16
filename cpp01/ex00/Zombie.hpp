/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:33:24 by mohimi            #+#    #+#             */
/*   Updated: 2024/12/06 14:33:24 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

#define color "\001\033[1;36m\002"
#define pos "\001\033[0;0m\002"
#define yellow "\001\033[1;33m\002"
#define grey "\001\033[1;30m\002"

class Zombie
{
    private:
        std::string _name;
    public:
        ~Zombie();
        Zombie(std::string name);
        Zombie* newZombie(std::string name);
        void randomChump(std::string name);
        void announce(void);
};
#endif