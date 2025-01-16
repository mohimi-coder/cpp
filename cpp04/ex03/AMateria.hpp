/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:50:06 by mohimi            #+#    #+#             */
/*   Updated: 2025/01/15 15:46:01 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP


#include <iostream>
#include <string>

# define RESET "\033[0m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define CYAN "\033[36m"
# define gold "\001\033[38;5;220m\002" 

class ICharacter;
class AMateria
{
    protected:
        std::string _type;
    public:
        AMateria(std::string const & type);
        AMateria();
        AMateria(const AMateria &other);
        virtual ~AMateria();
        AMateria &operator=(const AMateria &other);
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif
