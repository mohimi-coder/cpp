/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:21:15 by mohimi            #+#    #+#             */
/*   Updated: 2025/02/16 13:32:00 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _n(0)
{
}

Span::Span(unsigned int N): _n(N)
{
}

Span::Span(const Span &other) : _numbers(other._numbers), _n(other._n)
{
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _numbers = other._numbers;
        _n = other._n;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
    if (_numbers.size() == _n)
        throw Span::ContainerIsFullException();
    _numbers.push_back(number);
}

unsigned int Span::shortestSpan()
{
    if (_numbers.size() < 2) 
        throw Span::NotEnoughNumbersException(); //6,3,17,9,11 sort: 3,6,9,11,17
    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());
    int min_Span = tmp[1] - tmp[0]; // 6-3 = 3
    for (size_t i = 1; i < tmp.size(); i++) 
    {
        int current_Span = tmp[i] - tmp[i - 1];// 3
        if (current_Span < min_Span) 
            min_Span = current_Span;
    }
    return min_Span;
}

unsigned int Span::longestSpan()
{
    if (_numbers.size() < 2) 
        throw Span::NotEnoughNumbersException();
    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());
    return tmp[tmp.size() - 1] - tmp[0];
}

const char* Span::ContainerIsFullException::what() const throw()
{
    return "Cannot add number: The container is full.";
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
    return "Cannot calculate span: Not enough numbers in the container.";
}

void Span::addRandomNumbers()
{
    _numbers.resize(_n);
    std::generate(_numbers.begin(), _numbers.end(), std::rand);
}
