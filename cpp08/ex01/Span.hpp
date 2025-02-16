/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:14:17 by mohimi            #+#    #+#             */
/*   Updated: 2025/02/16 14:54:06 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>


class Span
{
    private:
        std::vector<int> _numbers;
        unsigned int _n;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();
        void addNumber(int number);
        unsigned int shortestSpan();
        unsigned int longestSpan();
        void addRandomNumbers();
        class ContainerIsFullException: public std::exception
        {
            virtual const char* what() const throw();
        };

        class NotEnoughNumbersException: public std::exception
        {
            virtual const char* what() const throw();
        };
};

#endif