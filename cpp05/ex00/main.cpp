/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:00:01 by mohimi            #+#    #+#             */
/*   Updated: 2025/01/28 15:55:43 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() 
{
    try 
    {
        std::cout << "===================== TEST 1 ===============================\n";
        Bureaucrat b1("mohimi", 1);
        std::cout << b1 << std::endl;

        Bureaucrat b2("Mohamed", 149);
        std::cout << b2 << std::endl;

        b2.decrementGrade();
        std::cout << b2 << std::endl;
        b2.decrementGrade();
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    try 
    {
        std::cout << "===================== TEST 2 ===============================\n";
        Bureaucrat b3("robot", 14);
        b3.incrementGrade();
        std::cout << b3 << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try 
    {
        std::cout << "===================== TEST 3 ===============================\n";
        Bureaucrat b4("who", 1);
        b4.decrementGrade();
        std::cout << b4 << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    try 
    {
        std::cout << "===================== TEST 4 ===============================\n";
        Bureaucrat b4("who", 1324);
        std::cout << b4 << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
