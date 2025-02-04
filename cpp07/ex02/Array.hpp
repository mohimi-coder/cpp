/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:48:05 by mohimi            #+#    #+#             */
/*   Updated: 2025/02/04 21:30:10 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <class T>

class Array
{
    private:
        T *_arr;
        size_t _size;
    public:
        Array();
        Array(size_t n);
        Array(const Array &obj);
        Array &operator=(const Array &obj);
        ~Array();
        T &operator[](size_t n);
        size_t size() const;
};
#include "Array.tpp"

#endif