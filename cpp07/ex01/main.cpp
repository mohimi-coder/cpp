/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:21:34 by mohimi            #+#    #+#             */
/*   Updated: 2025/02/07 16:14:20 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    std::string arr2[] = {"Hello", "World", "1337", "is", "awesome"};
    double arr3[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char arr4[] = {'a', 'b', 'c', 'd', 'e'};

    size_t arr_size = sizeof(arr) / sizeof(arr[0]);
    size_t arr2_size = sizeof(arr2) / sizeof(arr2[0]);
    size_t arr3_size = sizeof(arr3) / sizeof(arr3[0]);
    size_t arr4_size = sizeof(arr4) / sizeof(arr4[0]);

    std::cout << GOLD "==================Int array: =================" RESET << std::endl;

    iter(arr, arr_size, print<int>);

    std::cout << GREEN "==================String array: ===============" RESET<< std::endl;
    
    iter(arr2, arr2_size, print<std::string>);

    std::cout << YELLOW "===================Double array: ===============" RESET<< std::endl;

    iter(arr3, arr3_size, print<double>);

    std::cout << CYAN "===================Char array: ==================" RESET << std::endl;

    iter(arr4, arr4_size, print<char>);
    return 0;
}
