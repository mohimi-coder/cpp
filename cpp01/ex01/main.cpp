/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:33:35 by mohimi            #+#    #+#             */
/*   Updated: 2024/12/06 14:33:35 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *my_horde = NULL;
    my_horde = zombieHorde(42, "mohimi");
    if(my_horde == NULL)
        return (1);
    for(int index = 0; index < 42; index++)
    {
        std::cout << grey << "ZombieHorde Index: " << index << pos << std::endl;
        my_horde[index].announce();
    }
    delete[] my_horde;
}