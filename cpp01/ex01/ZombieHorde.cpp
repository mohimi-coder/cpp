/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:34:08 by mohimi            #+#    #+#             */
/*   Updated: 2024/12/06 14:34:08 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *new_horde = NULL;
    if(N < 1)
        return (NULL);
    new_horde = new Zombie[N];
    if(new_horde == NULL)
        return (NULL);
    for(int index = 0; index < N; index++)
    {
        new_horde[index].set_name(name);
    }
    return new_horde;
}