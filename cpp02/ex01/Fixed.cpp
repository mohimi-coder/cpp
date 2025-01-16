/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:00:16 by mohimi            #+#    #+#             */
/*   Updated: 2024/12/25 18:13:50 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(int const value)
{
    std::cout << "Int constructor called" << std::endl;
    _value = value << _fractional_bits;
}

Fixed::Fixed(float const value)
{
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(value * (1 << _fractional_bits));
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    if (this == &fixed)
    {   
        std::cout << "Copy assignment operator called" << std::endl;
        return *this;
    }
    std::cout << "Copy assignment operator called" << std::endl;
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