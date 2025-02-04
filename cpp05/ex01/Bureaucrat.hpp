/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 21:47:49 by mohimi            #+#    #+#             */
/*   Updated: 2025/01/28 15:58:18 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include <ostream>

#include "Form.hpp"

# define RESET "\033[0m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define CYAN "\033[36m"
# define gold "\001\033[38;5;220m\002" 

class Form;

class Bureaucrat
{
    private:
       const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        const std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(Form &form);
        class GradeTooHighException : public std::exception 
        {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception 
        {
            public:
                const char* what() const throw();
        };
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &value);

#endif