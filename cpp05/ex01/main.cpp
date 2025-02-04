/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:14:26 by mohimi            #+#    #+#             */
/*   Updated: 2025/01/28 16:01:47 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    std::cout << "================================================Test 1======================================" << std::endl;
    try
    {
        Bureaucrat b("Bureaucrat", 9);
        Form f("Form", 8, 14);
        std::cout << f;
        b.incrementGrade();
        std::cout << b << std::endl;
        b.signForm(f);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "================================================Test 2======================================" << std::endl;
    try
    {
        Bureaucrat b("Bureaucrat", 150);
        Form f("Form", 1, 150);
        std::cout << b << std::endl;
        std::cout << f;
        b.signForm(f);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "================================================Test 3======================================" << std::endl;
    try
    {
        Bureaucrat b("Bureaucrat", 1);
        Form f("Form", 130, 150);
        std::cout << b  << std::endl;
        std::cout << f;
        b.signForm(f);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "============================================================================================" << std::endl;
    return 0;
}

