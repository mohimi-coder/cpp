/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:26:21 by mohimi            #+#    #+#             */
/*   Updated: 2024/12/22 12:36:36 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0))
{
}
Point::Point(const float x_val, const float y_val) : x(Fixed(x_val)), y(Fixed(y_val))
{
}
Point:: Point(const Point &other) : x(other.x), y(other.y)
{
}

Point::~Point()
{
}

Point &Point::operator=(const Point &other)
{
    (void)other;
    return *this;
}

Fixed const Point::get_x(void) const
{
    return this->x;
}
Fixed const Point::get_y(void) const
{
    return this->y;
}