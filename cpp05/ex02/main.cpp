/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:31:37 by mohimi            #+#    #+#             */
/*   Updated: 2025/01/28 16:10:57 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"


int main(void) {
    try 
    {
        Bureaucrat manager("Manager", 5);

        try 
        {
            ShrubberyCreationForm shrubbery("Garden");
            RobotomyRequestForm robotomy("Robot");
            PresidentialPardonForm pardon("Criminal");

            std::cout << "==========================================" << std::endl;

            manager.signForm(shrubbery);
            manager.signForm(robotomy);
            manager.signForm(pardon);

            std::cout << "============================================" << std::endl;

            manager.executeForm(shrubbery);
            std::cout << std::endl;
            manager.executeForm(robotomy);
            std::cout << std::endl;
            manager.executeForm(pardon);

        } 
        catch (std::exception &e) 
        {
            std::cerr << e.what() << std::endl;
        }
    } 
    catch (std::exception &e) 
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}