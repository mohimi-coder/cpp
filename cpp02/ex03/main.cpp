/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:45:49 by mohimi            #+#    #+#             */
/*   Updated: 2024/12/22 12:48:46 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main() 
{
    Point a(9, 4);
    Point b(4, 8); 
    Point c(2, 4);
    Point point(4, 4);

    if (bsp(a, b, c, point)) 
        std::cout << color << "The point is inside the triangle." << pos << std::endl;
    else
        std::cout << grey << "OOPs: The point is outside the triangle." << pos << std::endl;

    return 0;
}
