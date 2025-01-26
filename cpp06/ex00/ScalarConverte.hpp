/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverte.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:58:36 by mohimi            #+#    #+#             */
/*   Updated: 2025/01/24 22:22:48 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <limits>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <iostream>
#include <string>

class ScalarConverte
{
    private:
        double d;
        bool is_float;
    public:
        ScalarConverte();
        ScalarConverte(const ScalarConverte &other);
        ~ScalarConverte();
        ScalarConverte &operator=(const ScalarConverte &other);
        static void convert(std::string &str);
};

int isChar(std::string &str);
int isInt(std::string &str);
int isFloat(std::string &str);
int isDouble(const std::string &str);
int isSpecial(std::string &str);

        //convert functions
int convertToInt(std::string &str);
float convertToFloat(std::string &str);
double convertToDouble(std::string &str);
#endif