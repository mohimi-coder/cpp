/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:49:20 by mohimi            #+#    #+#             */
/*   Updated: 2025/02/21 14:39:42 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>

#define RED "\033[1;31m"
#define pos "\001\033[0;0m\002"
#define gold "\001\033[38;5;220m\002" 
#define grey "\001\033[1;30m\002"

class BitcoinExchange
{
    private:
        std::map<std::string, float> data;
        bool valid_Data(std::string line);
        bool valid_Input(std::string line);
        bool dateCheck(std::string &str);
        bool valueCheck(std::string &str);
        
        void check_CsvFile();
        void input_FileCheck(char *str);
        void bitcoinExchange(char *str);
        void infoCheck(std::string &str);
        void printBitcoin(std::string &str, float value);
        
        BitcoinExchange(const BitcoinExchange &obj);
        BitcoinExchange &operator=(const BitcoinExchange &obj);
    public:
        ~BitcoinExchange();
        BitcoinExchange();
        
        void loadDatabase(char *file);

        class Errors : public std::exception
        {
            public:
                const char *what() const throw();
        };
};
#endif