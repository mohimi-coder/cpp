/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:52:27 by mohimi            #+#    #+#             */
/*   Updated: 2025/03/09 13:49:09 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
    data = obj.data;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
    if (this != &obj)
    {
        data = obj.data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::loadDatabase(char *file)
{
    check_CsvFile();
    input_FileCheck(file);
    bitcoinExchange(file);
}

void BitcoinExchange::check_CsvFile()
{
    std::ifstream file("data.csv");
    if (!file)
    {
        std::cerr << RED << "data.csv not found" << pos << std::endl;
        throw Errors();
    }
    std::string line;
    size_t date_size;
    float value;
    if(std::getline(file, line).eof())
    {
        std::cerr << RED << "data.csv is empty!"<< pos << std::endl;
        throw Errors();
    }
    while(std::getline(file, line))
    {
        if (line != "data,exchange_rate")
        {
            date_size = line.find(',');
            if (valid_Data(line.substr(0, date_size)) == false)
            {
                std::cerr << RED << "Invalid date" << pos << std::endl;
                throw Errors();
            }
            if (valid_Input(line.substr(date_size + 1, line.length())) == false)
            {
                std::cerr << RED << "Invalid value" << pos << std::endl;
                throw Errors();
            }
            std::stringstream ss(line.substr(date_size + 1, line.length()));
            ss >> value;
            data[line.substr(0, date_size)] = value;
        }
    }
}

bool BitcoinExchange::valid_Data(std::string line)
{
    if (line.length() != 10)
        return false;
    std::string get_date;
    std::stringstream ss(line);
    int year;
    int month;
    int day;
    int i = 0;

    while(std::getline(ss, get_date, '-'))
    {
        if (i == 0)
        {
            std::stringstream ss(get_date);
            ss >> year;
            if (year < 1000 || year > 9999)
                return false;
        }
        else if (i == 1)
        {
            std::stringstream ss(get_date);
            ss >> month;
            if (month < 1 || month > 12)
                return false;
        }
        else if (i == 2)
        {
            std::stringstream ss(get_date);
            ss >> day;
            if (day < 1 || day > 31)
                return false;
            if (day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
                return false;
            if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
            {
                if (day > 29 && month == 2)
                    return false;
            }
            else if (day > 28 && month == 2)
                return false;
        }
        i++;
    }
    if (i != 3)
        return false;
    return true;
}

bool BitcoinExchange::valid_Input(std::string line)
{
    char *ptr = NULL;
    double value = std::strtod(line.c_str(), &ptr);
    if (value == 0.0 && !std::isdigit(line[0]))
        return false;
    if (*ptr && strcmp(ptr, "f") != 0)
        return false;
    return true;
}

void BitcoinExchange::input_FileCheck(char *str)
{
    std::fstream infile(str);
    if (!infile)
    {
        std::cerr << RED << "Error: could not open file." << pos << std::endl;
        throw Errors();
    }
    std::string line;
    if (std::getline(infile, line).eof())
    {
        std::cerr << RED << "Error: file is empty." << pos << std::endl;
        throw Errors();
    }
    if (line.compare("date | value") != 0)
    {
        std::cerr << RED << "Error: invalid file format." << pos << std::endl;
        throw Errors();
    }
    line.erase();
    infile.close();
}

void BitcoinExchange::bitcoinExchange(char *str)
{
    std::fstream infile(str);
    std::string line;
    std::getline(infile, line);
    while (std::getline(infile, line))
    {
        infoCheck(line);
    }
}

void BitcoinExchange::infoCheck(std::string &str)
{
    std::string date;
    std::string info;

    std::stringstream ss(str);
    float value;
    int i = 0;
    while(std::getline(ss, info, ' '))
    {
        if (i == 0)
        {
            if (dateCheck(info) == false)
                return;
            date = info;
        }
        if (i == 1 && info != "|")
        {
            std::cerr << RED << "Error: bad input => " << pos << str << std::endl;
            return;
        }
        if (i == 2)
        {
            if (valueCheck(info) == false)
                return;
            value = std::strtod(info.c_str(), NULL);
            if (value > 1000)
            {
                std::cerr << RED << "Error: value too high" << pos << std::endl;
                return;
            }
        }
        i++;
    }
    if (i != 3)
    {
        std::cerr << RED << "Error: bad input => "<< pos << str << std::endl;
        return;
    }
    printBitcoin(date, value);
}

bool BitcoinExchange::dateCheck(std::string &str)
{
    std::string get_date;
    std::stringstream ss(str);
    int year;
    int month;
    int day;

    int i = 0;
    if (str.find('-', str.length() - 1) != std::string::npos)
    {
        std::cerr << RED << "Error: bad input => " << pos << str << std::endl;
        return false;
    }
    while(std::getline(ss, get_date, '-'))
    {
        if (i == 0)
        {
            std::stringstream ss(get_date);
            ss >> year;
            if (year < 2009 || year > 2022)
            {
                std::cerr << RED << "Error: bad input => " << pos << str << std::endl;
                return false;
            }
        }
        if (i == 1)
        {
            std::stringstream ss(get_date);
            ss >> month;
            if (month < 1 || month > 12)
            {
                std::cerr << RED << "Error: bad input => " << pos << str << std::endl;
                return false;
            }
        }
        if (i == 2)
        {
            std::stringstream ss(get_date);
            ss >> day;
            if (day < 1 || day > 31)
            {
                std::cerr << RED << "Error: bad input => " << pos << str << std::endl;
                return false;
            }
            if (day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
            {
                std::cerr << RED << "Error: bad input => " << pos << str << std::endl;
                return false;
            }
            if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
            {
                if (day > 29 && month == 2)
                {
                    std::cerr << RED << "Error: bad input => "<< pos << str << std::endl;
                    return false;
                }
            }
            else if (day > 28 && month == 2)
            {
                std::cerr << RED << "Error: bad input => " << pos << str << std::endl;
                return false;
            }
        }
        i++;
    }
    if (i != 3)
    {
        std::cerr << RED << "Error: bad input => " << pos << str << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::valueCheck(std::string &str)
{
    char *ptr = NULL;
    double value = std::strtod(str.c_str(), &ptr);

    if (str.find('.', 0) == 0 || str.find('.', str.length() - 1) != std::string::npos)
    {
        std::cout << RED << "Error: not a Number" << pos << std::endl;
        return false;
    }
    if (value == 0.0 && !std::isdigit(str[0]))
    {
        std::cout << RED << "Error: not a Number" << pos << std::endl;
        return false;
    }
    if (*ptr && std::strcmp(ptr, "f"))
    {
        std::cout << RED << "Error: not a Number" << pos << std::endl;
        return false;
    }
    if (value < 0)
    {
        std::cout << RED << "Error: not a positive number." << pos << std::endl;
        return false;
    }
    if (str.length() > 10 || (str.length() == 10 && value > 2147483647))
    {
        std::cout << RED << "Error: too large a number." << pos << std::endl;
        return false;
    }
    return true;
}

void BitcoinExchange::printBitcoin(std::string &str, float value)
{
    std::map<std::string, float>::iterator it;
    float result;

    result = 0.0f;
    {
        it = data.lower_bound(str);
        if (it == data.begin())
        {
            std::cerr << RED <<"Error: invalid date" << pos << std::endl;
            return;
        }
        if (it->first != str)
            --it;
        result = (it->second) * value;
    }
    if (value == static_cast<int>(value))
        std::cout << gold << str << " => " << static_cast<int>(value) << " = " << pos << result << std::endl;
    else
        std::cout << gold << str << " => " << value << " = " << pos << result << std::endl;
}

const char *BitcoinExchange::Errors::what() const throw()
{
    return "Error";
}