/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:47:08 by mohimi            #+#    #+#             */
/*   Updated: 2024/12/22 12:46:22 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

#define color "\001\033[1;36m\002"
#define pos "\001\033[0;0m\002"
#define yellow "\001\033[1;33m\002"
#define grey "\001\033[1;30m\002"

class Point
{
    private:
        const Fixed x;
        const Fixed y;
    public:
        Point();
        Point(const float x_val, const float y_val);
        Point(const Point &other);
        Point &operator=(const Point &other);
        ~Point();
        const Fixed get_x(void) const;
        const Fixed get_y(void) const;
};
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif