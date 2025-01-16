/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:42:18 by mohimi            #+#    #+#             */
/*   Updated: 2024/12/11 10:42:48 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

#define color "\001\033[1;36m\002"
#define res "\001\033[0;0m\002"
#define b_ora "\001\033[1;38;5;208m\002"
#define violet "\001\033[38;5;128m\002"

class Harl
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
	public:
		void complain( std::string level );
		Harl();
		~Harl();
};
#endif