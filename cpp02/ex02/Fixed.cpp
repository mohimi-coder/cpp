/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:45:22 by mohimi            #+#    #+#             */
/*   Updated: 2025/02/07 20:20:10 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

Fixed::Fixed() : _value(0)
{
}
Fixed::Fixed(int const value)
{
    _value = value << _fractional_bits;
}

Fixed::Fixed(float const value)
{
    _value = roundf(value * (1 << _fractional_bits));
}

Fixed::Fixed(const Fixed &fixed)
{
    *this = fixed;
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    if (this == &fixed)
        return *this;
    _value = fixed._value;
    return *this;
}
int Fixed::toInt( void ) const
{
    return _value >> _fractional_bits;
}

float Fixed::toFloat( void ) const
{
    return (float)_value / (1 << _fractional_bits);
}

int Fixed::getRawBits(void) const
{
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}
std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
    out << value.toFloat();
    return out;
}

bool Fixed::operator>(const Fixed &fixed) const
{
    return _value > fixed._value;
}

bool Fixed::operator<(const Fixed &fixed) const
{
    return _value < fixed._value;
}

bool Fixed::operator>=(const Fixed &fixed) const
{
    return _value >= fixed._value;
}

bool Fixed::operator<=(const Fixed &fixed) const
{
    return _value <= fixed._value;
}

bool Fixed::operator==(const Fixed &fixed) const
{
    return _value == fixed._value;
}

bool Fixed::operator!=(const Fixed &fixed) const
{
    return _value != fixed._value;
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
    Fixed result;
    result._value = _value + fixed._value;
    return result;
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
    Fixed result;
    result._value = _value - fixed._value;
    return result;
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
    Fixed result;
    result._value = _value * fixed.toFloat();
    return result;
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
    Fixed result;
    result._value = _value / fixed._value;
    return result;
}

 Fixed &Fixed::operator++(void)
{
    _value++;
    return *this;
}
 
Fixed Fixed::operator++(int i)
{
    Fixed tmp = *this;
    if (i == 0)
       i = 1;
    this->_value += i;
    return tmp;  
}

Fixed &Fixed::operator--(void)
{
    _value--;
    return *this;
}

Fixed Fixed::operator--(int i)
{
    Fixed tmp = *this;
    if (i == 0)
       i = 1;
    this->_value -= i;
    return tmp;  
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    else
        return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    else
        return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    //a < b ? a : b;
    if (a < b)
        return a;
    else
        return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    //a > b ? a : b;
    if (a > b)
        return a;
    else
        return b;
}
