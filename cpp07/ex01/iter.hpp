/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:50:25 by mohimi            #+#    #+#             */
/*   Updated: 2025/02/04 11:06:22 by mohimi           ###   ########.fr       */
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

template <class T, class F>

void iter(T *arr, size_t lengh, F func)
{
    for (size_t i = 0; i < lengh; i++)
    {
        func(arr[i]);
    }
}

template <class T>

void print(T const &x)
{
    std::cout << x << " " << std::endl;
}

template <class T>

void increment(T &x)
{
    x += 1;
}
#endif