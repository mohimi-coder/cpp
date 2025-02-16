/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:10:20 by mohimi            #+#    #+#             */
/*   Updated: 2025/02/16 13:39:49 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <class T>

MutantStack<T>::MutantStack()
{
}

template <class T>

MutantStack<T>::MutantStack(MutantStack &other) : std::stack<T>(other)
{
    *this = other;
}

template <class T>

MutantStack<T> &MutantStack<T>::operator=(MutantStack &other)
{
    if (this != &other)
        std::stack<T>::operator=(other);
    return *this;
}

template <class T>

MutantStack<T>::~MutantStack()
{
}
