/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:07:13 by mohimi            #+#    #+#             */
/*   Updated: 2025/01/20 11:21:42 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("uknown"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    _signed = false;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}
AForm::~AForm()
{
}

AForm::AForm(const AForm &other) : _name(other.getName()), _gradeToSign(other.getGradeToSign()), _gradeToExecute(other.getGradeToExecute())
{
    _signed = other.getSigned();
}

const char* AForm::GradeTooHighException::what() const throw() 
{
    return GREEN "Grade is too high!" RESET;
}

const char* AForm::GradeTooLowException::what() const throw() 
{
    return RED "Grade is too low!" RESET;
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        _signed = other._signed;
    return *this;
}

const std::string AForm::getName() const
{
    return _name;
}

bool AForm::getSigned() const
{
    return _signed;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    if (getSigned())
        throw GradeTooHighException();
    _signed = true;

    std::cout << "Debug: Form signed successfully" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const AForm &value)
{
    out << "AForm: " << value.getName() << " is ";
    if (value.getSigned())
        out << CYAN "signed" RESET;
    else
        out << RED "not signed" RESET << std::endl;
    out << gold " and requires grade " RESET << value.getGradeToSign() << gold " to sign and grade "  RESET << value.getGradeToExecute() << gold " to execute." RESET << std::endl;
    return out;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
    if (getSigned() == false)
        throw GradeTooHighException();
    doAction();
}