/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverte.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:01:05 by mohimi            #+#    #+#             */
/*   Updated: 2025/02/04 18:08:57 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverte.hpp"

ScalarConverte::ScalarConverte()
{
}
ScalarConverte::ScalarConverte(const ScalarConverte &other)
{
    *this = other;
}

ScalarConverte::~ScalarConverte()
{
}

ScalarConverte &ScalarConverte::operator=(const ScalarConverte &other)
{
    (void)other;
    return (*this);
}

int non_printable(std::string &str)
{
    for(size_t i = 0; i < str.length(); i++)
    {
        if (str[i] < 32 || str[i] > 126)
            return (1);
    }
    return (0);
}

int isChar(std::string &str)
{
    if (str.length() == 1 && !std::isdigit(str[0]))
        return (1);
    return (0);
}

int isInt(std::string &str)
{
    if (str.length() == 1 && std::isdigit(str[0]))
        return (1);
    if (str.length() > 1 && (str[0] == '-' || str[0] == '+'))
    {
        for(size_t i = 1; i < str.length(); i++)
        {
            if (!std::isdigit(str[i]))
                return (0);
        }
        return (1);
    }
    for(size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return (0);
    }
    return (1);
}

int isDouble(const std::string &str)
{
    int dot = 0;
    if (str.length() == 1 && std::isdigit(str[0]))
        return (1);
    if (str.length() > 1 && (str[0] == '-' || str[0] == '+'))
    {
        for(size_t i = 1; i < str.length(); i++)
        {
            if (str[i] == '.')
                dot++;
            if (!std::isdigit(str[i]) && str[i] != '.')
                return (0);
        }
        if (dot == 1)
            return (1);
    }
    for(size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == '.')
            dot++;
        if (!std::isdigit(str[i]) && str[i] != '.')
            return (0);
    }
    if (dot == 1)
        return (1);
    return (0);
}

int isFloat(std::string &str)
{
    if (str.length() > 1 && str[str.length() - 1] == 'f' && isDouble(str.substr(0, str.length() - 1)))
        return (1);
    return (0);
}

int isSpecial(std::string &str)
{
   return (str == "-inf" || str == "+inf" || str == "nan" || str == "-inff" || str == "+inff" || str == "nanf");
}

int convertToInt(std::string &str)
{
    std::stringstream s(str);
    int i;
    s >> i;
    if (s.fail())
        throw std::runtime_error(RED "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" RESET);
    return (i);
}

float convertToFloat(std::string &str)
{
    std::stringstream s(str);
    float f;
    s >> f;
    if (s.fail() || s.eof())
        throw std::runtime_error(RED "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" RESET);
    return (f);
}

double convertToDouble(std::string &str)
{
    std::stringstream s(str);
    double d;
    s >> d;
    if (s.fail() || !s.eof())
        throw std::runtime_error(RED "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" RESET);
    return (d);
}

void ScalarConverte::convert(std::string &str)
{
    try
    {
        if (non_printable(str))
            throw std::runtime_error(RED "invalid input" RESET);
        if (isChar(str))
        {
            char c = str[0];
            std::cout << "char: ";
            if ((c >= 0 && c < 32) || c == 127)
                std::cout << RED "Non displayable" RESET  << std::endl;
            else
                std::cout << Gold "'" << c << "'" RESET << std::endl;
            std::cout << Gold "int: " RESET << static_cast<int>(c) << std::endl;
            std::cout << Gold "float: " RESET << static_cast<float>(c) << ".0f" << std::endl;
            std::cout << Gold "double: " RESET << static_cast<double>(c) << ".0" << std::endl;
            return;
        }
        else if (isInt(str))
        {
            int i = convertToInt(str);
            std::cout << "char: ";
            if (i > std::numeric_limits<char>::max() || i < std::numeric_limits<char>::min())
                std::cout << RED "impossible" RESET << std::endl;
            else if (i < 0 || (i >= 0 && i < 32) || i == 127)
                std::cout << RED "Non displayable" RESET << std::endl;
            else
                std::cout << Gold "'" RESET<< static_cast<char>(i) << "'" << std::endl;
            std::cout << Gold "int: " RESET << i << std::endl;
            std::cout << Gold "float: " RESET << static_cast<float>(i) << ".0f" << std::endl;
            std::cout << Gold "double: " RESET << static_cast<double>(i) << ".0" << std::endl;
            return;
        }
        else if (isFloat(str))
        {
            float f = convertToFloat(str);
            std::cout << "char: ";
            if (f > std::numeric_limits<char>::max() || f < std::numeric_limits<char>::min())
                std::cout << RED "impossible" RESET << std::endl;
            else if (f < 0 || (f >= 0 && f < 32) || f == 127)
                std::cout << RED "Non displayable" RESET << std::endl;
            else
                std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
            if (f > 2147483647 || f < -2147483648)
                std::cout << RED "int: impossible" RESET << std::endl;
            else
                std::cout << Gold "int: " RESET << static_cast<int>(f) << std::endl;
            std::cout << Gold "float: " RESET << std::fixed << std::setprecision(1) << f << "f" << std::endl;
            std::cout << Gold "double: " RESET << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
            return;
        }
        else if (isDouble(str))
        {
            double d = convertToDouble(str);
            std::cout << "char: ";
            if (d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min())
                std::cout << RED "impossible" RESET << std::endl;
            else if (d < 0 || (d >= 0 && d < 32) || d == 127)
                std::cout << RED "Non displayable" RESET << std::endl;
            else
                std::cout << Gold "'" << static_cast<char>(d) << "'" RESET << std::endl;
            if (d > 2147483647 || d < -2147483648)
                std::cout << RED "int: impossible" RESET << std::endl;
            else
                std::cout << Gold "int: " RESET << static_cast<int>(d) << std::endl;
            std::cout << Gold "float: " RESET << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
            std::cout << Gold "double: " RESET << std::fixed << std::setprecision(1) << d << std::endl;
            return;
        }
        else if (isSpecial(str))
        {
           if (str == "-inf" || str == "-inff")
            {
                std::cout << RED "char: impossible" RESET << std::endl;
                std::cout << RED "int: impossible" RESET << std::endl;
                std::cout << Gold "float: -inff" RESET << std::endl;
                std::cout << Gold "double: -inf" RESET << std::endl;
                return;
            }
            if (str == "+inf" || str == "+inff")
            {
                std::cout << RED "char: impossible" RESET << std::endl;
                std::cout << RED "int: impossible" RESET << std::endl;
                std::cout << Gold "float: +inff" RESET << std::endl;
                std::cout << Gold "double: +inf" RESET << std::endl;
                return;
            }
            if (str == "nan" || str == "nanf")
            {
                std::cout << RED "char: impossible" RESET<< std::endl;
                std::cout << RED "int: impossible" RESET << std::endl;
                std::cout << Gold "float: nanf" RESET << std::endl;
                std::cout << Gold "double: nan" RESET << std::endl;
                return;
            }
        }
        throw std::runtime_error(RED "invalid input" RESET);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}