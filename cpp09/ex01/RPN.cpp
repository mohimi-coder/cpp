/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:44:34 by mohimi            #+#    #+#             */
/*   Updated: 2025/02/23 11:47:23 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const std::string &str) : _input(str)
{}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        _input = other._input;
        _num = other._num;
        _str = other._str;
        numbers = other.numbers;
    }
    return *this;
}

RPN::~RPN()
{}

const char* RPN::ErrorException::what() const throw()
{
    return "Error";
}

void RPN::fixInput()
{
    std::stringstream ss(_input);
    std::string str;
    std::stack<std::string> tmp;
    while(std::getline(ss, str, ' '))
    {
        if(str.empty())
            continue;
        tmp.push(str);
    }
    numbers = 0;
    while (!tmp.empty())
    {
        validInput(tmp.top());
        _str.push(tmp.top());
        tmp.pop();
    }
    int check = 2 * numbers - _str.size();
    if (check!= 1)
        throw RPN::ErrorException();
    addThings();
}

bool RPN::isOperators(char oper)
{
    if(oper == '+' || oper == '-' || oper == '*' || oper == '/')
        return true;
    return false;
}

void RPN::validInput(std::string input)
{
    if (input.length() == 1 && isOperators(input[0]))
        return;
    char *ptr = NULL;
    double value = std::strtod(input.c_str(), &ptr);
    if(value == 0.0 && !std::isdigit(input[0]))
        throw RPN::ErrorException();
    if (value < 0 || value > 9)
        throw RPN::ErrorException();
    if (*ptr && strcmp(ptr, "f"))
        throw RPN::ErrorException();
    numbers++;     
}

double RPN::resultCalculate(double f_operand, double s_operand, char oper)
{
    if (oper == '+')
        return(f_operand + s_operand);
    if (oper == '-')
        return (f_operand - s_operand);
    if (oper == '*')
        return (f_operand * s_operand);
    if (oper == '/')
    {
        if (s_operand == 0)
            throw RPN::ErrorException();
    }
    return(f_operand / s_operand);
}

void RPN::addThings()
{
    double s_b = 0.0;
    double f_a = 0.0;
    double result = 0.0;
    double calcule = 0.0;
    
    std::string tmp_buffer;
    
    while(!_str.empty())
    {
        tmp_buffer = _str.top();
        if (isOperators(tmp_buffer[0]))
        {
            if (_num.size() < 2)
                throw RPN::ErrorException();
            s_b = _num.top();
            _num.pop();
            f_a = _num.top();
            _num.pop();
            calcule = resultCalculate(f_a, s_b, tmp_buffer[0]);
            _num.push(calcule);
            _str.pop();
        }
        else 
        {
            result = std::strtod(_str.top().c_str(), NULL);
            _num.push(result);
            _str.pop();
        }
    }
    std::cout << _num.top() << std::endl;
}