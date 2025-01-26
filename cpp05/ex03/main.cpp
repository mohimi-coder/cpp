/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:31:37 by mohimi            #+#    #+#             */
/*   Updated: 2025/01/26 17:12:14 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main( void ) 
{
	Intern	someRandomIntern;

	try 
	{
		AForm	*scf;
		scf = someRandomIntern.makeForm("ShrubberyCreationForm", "mehdi" );
		delete scf;

		AForm	*rrf;
		rrf = someRandomIntern.makeForm("RobotomyRequestForm", "mohimi" );
		delete rrf;

		AForm	*rrrf;
		rrrf = someRandomIntern.makeForm("PresidentialPardonForm", "zmaghdao" );
		delete rrrf;

		rrf = someRandomIntern.makeForm( "sheese burger creation form", "you" );
	} 
	catch ( std::exception &e ) 
	{
		std::cerr << e.what() << std::endl;
	}
}