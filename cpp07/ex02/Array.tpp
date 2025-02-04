/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 21:17:28 by mohimi            #+#    #+#             */
/*   Updated: 2025/02/04 21:34:43 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <class T>

Array<T>::Array() : _arr(NULL), _size(0)
{
}

template <class T>

Array<T>::Array(size_t n) : _arr(new T[n]()), _size(n)
{
}

template <class T>

Array<T>::Array(const Array &obj)
{
    _size = obj._size;
    _arr = new T[_size];
    for (size_t i = 0; i < _size; i++)
        _arr[i] = obj._arr[i];
}

template <class T>

Array<T> &Array<T>::operator=(const Array &obj)
{
    if (this != &obj)
    {
        delete[] _arr;
        _size = obj._size;
        _arr = new T[_size];
        for (size_t i = 0; i < _size; i++)
            _arr[i] = obj._arr[i];
    }
    return *this;
}

template <class T>

Array<T>::~Array()
{
    delete[] _arr;
}

template <class T>

T &Array<T>::operator[](size_t n)
{
    if (n >= _size)
        throw std::out_of_range("Index out of range");
    return _arr[n];
}

template <class T>

size_t Array<T>::size() const
{
    return _size;
}