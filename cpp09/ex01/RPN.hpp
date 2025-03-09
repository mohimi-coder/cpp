/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 21:55:23 by mohimi            #+#    #+#             */
/*   Updated: 2025/02/22 15:26:30 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <cstring>
#include <sstream>
#include  <cstdlib>

class RPN
{
    private:
        std::string _input;
        std::stack<double> _num;
        std::stack<std::string> _str;
        int numbers;
        bool isOperators(char oper);
        void validInput(std::string input);
        double resultCalculate(double f_operand, double s_operand, char oper);
    public:
        RPN();
        RPN(const std::string &str);
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        void fixInput();
        void addThings();
        class ErrorException : public std::exception  
        {
        public:
            const char* what() const throw();
        };   
};

#endif