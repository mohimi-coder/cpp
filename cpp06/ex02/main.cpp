/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:42:33 by mohimi            #+#    #+#             */
/*   Updated: 2025/02/04 15:21:17 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
    Base* base = generate();
    std::cout << RED "*|=================Pointer: ========================|*" RESET << std::endl;
    identify(base);
    std::cout << Gold "*|=================Reference: ======================|*" RESET << std::endl;
    identify(*base);
    delete base;
    return 0;
}