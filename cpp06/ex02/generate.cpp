/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:46:46 by mohimi            #+#    #+#             */
/*   Updated: 2025/02/06 11:53:43 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base* generate(void)
{
    srand(time(0));
    int random = rand() % 3;
    if (random == 0)
        return new A;
    else if (random == 1)
        return new B;
    else
        return new C;
}

void identify(Base* p)
{
    if (p == NULL)
        return;
    if (dynamic_cast<A*>(p))
        std::cout << Gold "A" RESET << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << BLUE "B" RESET << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << GREEN "C" RESET << std::endl;
}

void identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << Gold "A" RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        try
        {
            B &b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << BLUE "B" RESET<< std::endl;
        }
        catch(const std::exception& e)
        {
            try
            {
                C &c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << GREEN "C" RESET << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cerr << RED "Error: " RESET << e.what() << std::endl;
            }
        }
    }
}