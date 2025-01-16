/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:24:03 by mohimi            #+#    #+#             */
/*   Updated: 2025/01/15 15:35:58 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"


int main() 
{ 
    IMateriaSource* src = new MateriaSource(); 
    src->learnMateria(new Ice()); 
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp; 
    tmp = src->createMateria("ice"); 
    me->equip(tmp); 
    tmp = src->createMateria("cure"); 
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->unequip(1);
    me->unequip(0);
    me->use(1, *bob); 
    me->use(1, *bob); 

    std::cout << "========================= tests =========================" << std::endl;
    tmp = src->createMateria("ice"); 
    me->equip(tmp); 
    tmp = src->createMateria("cure"); 
    me->equip(tmp);
    tmp = src->createMateria("fire"); 
    me->equip(tmp); 
    tmp = src->createMateria("fire");
    me->equip(tmp);
    me->use(0, *bob); 
    me->use(1, *bob);   
    delete bob; 
    delete me; 
    delete src;
    return 0; 
}
