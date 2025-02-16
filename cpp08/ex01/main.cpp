/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:34:59 by mohimi            #+#    #+#             */
/*   Updated: 2025/02/16 14:48:13 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>

int main()
{
    std::cout << "======================== Test 1: ==================" << std::endl;
    Span sp = Span(5);
    try{
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11); 
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "========================= Test 2: ===================" << std::endl;

    Span sp1 = Span(5);
    try{
        sp1.addNumber(1);
        sp1.addNumber(4);
        sp1.addNumber(5);
        sp1.addNumber(6);
        sp1.addNumber(10);
        // sp1.addNumber(11);
        std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp1.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << "========================= Test 3: ===================" << std::endl;
    std::srand(std::time(NULL));
    Span sp2 = Span(10000);
    try{
        sp2.addRandomNumbers();
        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << "========================= Test 4: ===================" << std::endl;
    
    Span sp3 = Span(1);
    try{
        sp3.addNumber(1);
        std::cout << sp3.shortestSpan() << std::endl;
        std::cout << sp3.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
      std::cout << "========================= Test 5: ===================" << std::endl;
    
    Span sp4 = Span(3);
    try{
        sp4.addNumber(1);
        sp4.addNumber(11);
        sp4.addNumber(52);
        sp4.addNumber(42);
        std::cout << "Shortest span: " << sp4.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp4.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}