/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:30:28 by mohimi            #+#    #+#             */
/*   Updated: 2025/01/15 12:00:48 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() 
{
    std::cout << "Default Brain constructed called!" << std::endl;
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = "no ideas";
}

Brain::Brain(std::string ideas)
{
    std::cout << "Brain Paramiterise constructor called!" << std::endl;
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = ideas;
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain Coppy constructor called!" << std::endl;
    *this = other;
}

Brain &Brain::operator=(const Brain &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = other._ideas[i];
    }
    std::cout << "Brain coppy assigned called!" << std::endl;
    return *this; 
}

Brain::~Brain() 
{
    std::cout << "Brain destructor called!" << std::endl;
}

void Brain::print(void) const
{
    for (int i = 0; i < 100; i++)
        std::cout << this->_ideas[i] << std::endl;
}