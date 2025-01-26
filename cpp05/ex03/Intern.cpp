/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:45:06 by mohimi            #+#    #+#             */
/*   Updated: 2025/01/26 22:12:03 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &other)
{
    *this = other;
}
 AForm *makeForm(const std::string form, const std::string target);
Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

const char* Intern::FormNotFoundException::what() const throw()
{
    return RED "Form not found!" RESET;
}

static AForm *presidentMaker(const std::string target)
{
    return (new PresidentialPardonForm(target));
}

static AForm *robotMaker(const std::string target)
{
    return (new RobotomyRequestForm(target));
}

static AForm *shrubberyMaker(const std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(const std::string form_creater, const std::string target_form)
{
    AForm *(*formMakers[])(const std::string target) = {&presidentMaker, &robotMaker, &shrubberyMaker};
    std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
    for(int i = 0; i < 3; i++)
    {
        if (form_creater == forms[i])
        {
            std::cout << gold <<  "Intern creates " << RESET<< CYAN << form_creater << RESET << std::endl;
            return(formMakers[i](target_form));
        }
    }
    std::cout << RED << "can not creat a form " << RESET << CYAN << form_creater << RESET << std::endl;
    return NULL;
}

