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

#include "Form.hpp"

Form::Form() : _name("uknown"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
}

Form::Form(const std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}
Form::~Form()
{
}

Form::Form(const Form &other) : _name(other.getName()), _gradeToSign(other.getGradeToSign()), _gradeToExecute(other.getGradeToExecute())
{
    _signed = other.getSigned();
}

const char* Form::GradeTooHighException::what() const throw() 
{
    return GREEN "Grade is too high!" RESET;
}

const char* Form::GradeTooLowException::what() const throw() 
{


    return RED "Grade is too low!" RESET;
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        _signed = other._signed;
    return *this;
}

const std::string Form::getName() const
{
    return _name;
}

bool Form::getSigned() const
{
    return _signed;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}

std::ostream &operator<<(std::ostream &out, const Form &value)
{
    out << "Form: " << value.getName() << " is ";
    if (value.getSigned())
        out << CYAN "signed" RESET;
    else
        out << RED "not signed" RESET << std::endl;
    out << gold " and requires grade " RESET << value.getGradeToSign() << gold " to sign and grade "  RESET << value.getGradeToExecute() << gold " to execute." RESET << std::endl;
    return out;
}