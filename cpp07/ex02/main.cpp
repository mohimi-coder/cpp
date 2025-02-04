/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 21:22:13 by mohimi            #+#    #+#             */
/*   Updated: 2025/02/04 21:36:51 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    try
    {
        Array<int> arr1;
        Array<int> arr2(5);
        
        for (size_t i = 0; i < arr2.size(); i++)
            arr2[i] = i * 2;
        
        Array<int> arr3(arr2);
        
        for (size_t i = 0; i < arr3.size(); i++)
            std::cout << arr3[i] << " ";
        std::cout << std::endl;
        
        arr3[2] = 1337;
        std::cout << "arr3[2]: " << arr3[2] << std::endl;
        std::cout << "arr2[2]: " << arr2[2] << std::endl;
        
        std::cout << "arr3 size: " << arr3.size() << std::endl;
        
        // This will throw an exception
        std::cout << arr3[10] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}