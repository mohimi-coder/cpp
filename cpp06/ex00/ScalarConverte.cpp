/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverte.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:01:05 by mohimi            #+#    #+#             */
/*   Updated: 2025/01/25 12:04:53 by mohimi           ###   ########.fr       */
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
    if (s.fail() || !s.eof())
        throw "impossible";
    return (i);
}

float convertToFloat(std::string &str)
{
    std::stringstream s(str);
    float f;
    if (!(s >> f))
        throw "impossible";
    return (f);
}

double convertToDouble(std::string &str)
{
    std::stringstream s(str);
    double d;
    s >> d;
    if (s.fail() || !s.eof())
        throw "impossible";
    return (d);
}

void ScalarConverte::convert(std::string &str)
{
    try
    {
        if (non_printable(str))
            throw "invalid input";
        if (isChar(str))
        {
            char c = str[0];
            if ((c >= 0 && c <= 32) || c == 127)
                std::cout << "char: Non displayable" << std::endl;
            else
                std::cout << "char: '" << c << "'" << std::endl;
            std::cout << "int: " << static_cast<int>(c) << std::endl;
            std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
            return;
        }
        else if (isInt(str))
        {
            int i = convertToInt(str);
            if (i < 0 || (i >= 0 && i <= 32) || i >= 127)
                std::cout << "char: Non displayable" << std::endl;
            else
                std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
            std::cout << "int: " << i << std::endl;
            std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
            return;
        }
        else if (isFloat(str))
        {
            float f = convertToFloat(str);
            std::cout << "char: ";
            if (f < 0 || (f >= 0 && f < 32) || f == 127)
                std::cout << "Non displayable" << std::endl;
            else
                std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
            std::cout << "int: " << static_cast<int>(f) << std::endl;
            std::cout << "float: " << f << ".ll0f" << std::endl;
            std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
            return;
        }
        else if (isDouble(str))
        {
            double d = convertToDouble(str);
             if (d < 0 || (d >= 0 && d <= 32) || d >= 127)
                std::cout << "char: Non displayable" << std::endl;
            else
                std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
            std::cout << "int: " << static_cast<int>(d) << std::endl;
            std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
            return;
        }
        else if (isSpecial(str))
        {
           if (str == "-inf" || str == "-inff")
            {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: -inff" << std::endl;
                std::cout << "double: -inf" << std::endl;
                return;
            }
            if (str == "+inf" || str == "+inff")
            {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: +inff" << std::endl;
                std::cout << "double: +inf" << std::endl;
                return;
            }
            if (str == "nan" || str == "nanf")
            {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: nanf" << std::endl;
                std::cout << "double: nan" << std::endl;
                return;
            }
        }
        throw "invalid input";
    }
    catch(const char *e)
    {
        std::cout << e << std::endl;
    }
}