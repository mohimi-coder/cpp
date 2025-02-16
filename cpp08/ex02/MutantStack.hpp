/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:20:23 by mohimi            #+#    #+#             */
/*   Updated: 2025/02/16 17:39:25 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <class T>

class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(MutantStack &other);
        MutantStack &operator=(MutantStack &other);
        ~MutantStack();
        typedef typename std::deque<T>::iterator iterator;

        iterator begin()
        {
            return this->c.begin();
        }
        iterator end()
        {
            return this->c.end();
        }
};

#include "MutantStack.tpp"

#endif