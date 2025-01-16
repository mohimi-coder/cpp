/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:01:15 by mohimi            #+#    #+#             */
/*   Updated: 2025/01/13 13:06:31 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i <= 3; i++)
        _materias[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i <= 3; i++)
        delete _materias[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i <= 3; i++)
    {
        if (_materias[i] == m)
            return ;
    }
    for (int i = 0; i <= 3; i++)
    {
        if (!_materias[i])
        {
            _materias[i] = m;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i <= 3; i++)
    {
        if (_materias[i] && _materias[i]->getType() == type)
            return _materias[i]->clone();
    }
    return NULL;
}