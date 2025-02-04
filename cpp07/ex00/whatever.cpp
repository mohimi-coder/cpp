/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:45:03 by mohimi            #+#    #+#             */
/*   Updated: 2025/02/03 14:47:57 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

Whatever::Whatever()
{
}

Whatever::Whatever(const Whatever &obj)
{
    *this = obj;
}
Whatever &Whatever::operator=(const Whatever &obj)
{
    (void)obj;
    return *this;
}

Whatever::~Whatever()
{
}