/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:29:30 by mohimi            #+#    #+#             */
/*   Updated: 2025/01/29 23:06:01 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Serializer s;
    Data *d = new Data(42, "Mohimi");
    uintptr_t raw = s.serialize(d);
    Data *d2 = s.deserialize(raw);
    std::cout << d2->_id << std::endl;
    std::cout << d2->_name << std::endl;
    delete d;
    return (0);
}