/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:50:25 by mohimi            #+#    #+#             */
/*   Updated: 2025/02/07 16:13:32 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define GOLD "\033[38;5;214m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

template <class T>

void iter(T *arr, size_t lenght, void (*f)(T &))
{
    for (size_t i = 0; i < lenght; i++)
        f(arr[i]);
}
template <class T>

void print(T  &x)
{
    std::cout << x << " " << std::endl;
}

#endif