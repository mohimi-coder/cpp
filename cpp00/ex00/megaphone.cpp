/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:31:43 by mohimi            #+#    #+#             */
/*   Updated: 2024/12/13 16:02:55 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	std::string tmp = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	if (ac > 1)
	{
		for (int i = 1; i < ac; i++)
		{
			std::string str = av[i];
			for (size_t j = 0; j < str.size(); j++)
				std::cout << (char)toupper(str.at(j));
		}
		std::cout << std::endl;
	}
	else
		std::cout << tmp << std::endl;
}
