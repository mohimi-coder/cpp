/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:32:56 by mohimi            #+#    #+#             */
/*   Updated: 2024/12/11 12:11:11 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) 
{
    Harl h_obj;
	std::string level;
    if (argc != 2) 
	{
        std::cerr << b_ora << "Usage: ./harlFilter <log level>" << res << std::endl;
        return 1;
    }
    level = argv[1];
    h_obj.harl_filter(level);
    return 0;
}