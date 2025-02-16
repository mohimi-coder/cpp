/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:35:21 by mohimi            #+#    #+#             */
/*   Updated: 2025/02/16 13:29:30 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);
    std::cout << "=========== list test ====================" << std::endl;
    try
    {
        std::cout << easyfind(lst, 50) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Value not found"<< std::endl;
    }
    
    try
    {
        std::cout << easyfind(lst, 80) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Value not found"<< std::endl;
    }
    std::cout << "=========== vector test ====================" << std::endl;
    try
    {
        std::cout << easyfind(vec, 10) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Value not found" << std::endl;
    }

    try
    {
        std::cout << easyfind(vec, 1) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Value not found" << std::endl;
    }
    return (0);
}