/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:43:02 by mohimi            #+#    #+#             */
/*   Updated: 2025/02/03 14:54:18 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template <class T>

void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <class T>

T min(T a, T b)
{
    if (a < b)
        return a;
    return b;
}

template <class T>

T max(T a, T b)
{
    if (a > b)
        return a;
    return b;
}
class Whatever
{
    public:
        Whatever();
        Whatever(const Whatever &obj);
        Whatever &operator=(const Whatever &obj);
        ~Whatever();
};

#endif