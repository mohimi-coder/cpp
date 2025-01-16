/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:35:34 by mohimi            #+#    #+#             */
/*   Updated: 2024/12/19 15:05:50 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdlib>

#define color "\001\033[1;36m\002"
#define res "\001\033[0;0m\002"
#define b_ora "\001\033[1;38;5;208m\002"
#define violet "\001\033[38;5;128m\002"

std::string replace_str(std::string &str, std::string &s1, std::string &s2)
{
	std::string result = str;
	size_t pos = result.find(s1);
	while(pos != std::string::npos)
	{
		result = result.substr(0, pos) + s2 + result.substr(pos + s1.length());
		pos = result.find(s1, pos + s2.length());
	}
	return result;
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << color << "+----------+----------+----------+----------+" << res << std::endl;
    	std::cout << b_ora << "|   Usage: "<<av[0]<<" <filename> <s1> <s2>   |" << res << std::endl;
    	std::cout << color << "+----------+----------+----------+----------+" << res << std::endl; 
		return 1;
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	if (s1.empty())
	{
        std::cerr << violet << "Error: s1 cannot be an empty string." << res << std::endl;
        return 1;
    }
	std::string s2 = av[3];
	std::ifstream file(filename.c_str());
	if (!file)
	{
		std::cerr << violet << "Error: could not open file." << res << std::endl;
		return 1;
	}
	std::string name_out = filename + ".replace";
	std::ofstream output(name_out.c_str());
	if (!output)
	{
		std::cerr << violet << "Error: could not create output file." << res << std::endl;
		return 1;
	}
	std::string line;
	while (std::getline(file, line))
	{
		if (std::cin.eof())
			exit(0);
		output << replace_str(line, s1, s2) << std::endl;
	}
	file.close();
	output.close();
	return 0;
}