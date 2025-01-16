/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:32:51 by mohimi            #+#    #+#             */
/*   Updated: 2024/12/06 14:32:51 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    std::cout << grey << "Allocation from Heap!" << pos << std::endl;
    Zombie *my_Zombie = NULL;
    my_Zombie = my_Zombie->newZombie("Foo");
    my_Zombie->announce();
    std::cout << grey << "Allocation from stack!" << pos << std::endl;
    my_Zombie->randomChump("Mohimi");
    delete my_Zombie;
}