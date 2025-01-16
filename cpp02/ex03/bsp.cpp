/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:47:12 by mohimi            #+#    #+#             */
/*   Updated: 2024/12/22 12:53:14 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


float triangle_ar(Point a, Point b, Point c)
{
    //⇒ Area of △ABC = ½[x1​(y2 ​− y3​) + x2​(y3 ​− y1​) + x3​(y1 ​− y2​)]
    Fixed r_triangle;
    r_triangle = a.get_x() * (b.get_y() - c.get_y()) + b.get_x() * (c.get_y() - a.get_y()) + c.get_x() * (a.get_y() - b.get_y());
    return abs(r_triangle.toFloat() / 2);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float A;
    float A1;
    float A2;
    float A3;

    A = triangle_ar(a, b,c);
    //Calculate the area of the triangle PAB, PBC, and PCA
    A1 = triangle_ar(point, a, b);
    A2 = triangle_ar(point, b, c);
    A3 = triangle_ar(point, c, a);

    // The point is inside the triangle if the sum of A1, A2, and A3 is equal to A
    return A == A1 + A2 + A3;   
}