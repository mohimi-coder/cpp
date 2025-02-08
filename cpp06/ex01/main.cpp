/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:29:30 by mohimi            #+#    #+#             */
/*   Updated: 2025/02/06 12:01:06 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data *d = new Data(42, "Mohimi");
    uintptr_t raw = Serializer::serialize(d);
    Data *d2 = Serializer::deserialize(raw);
    std::cout << d2->_id << std::endl;
    std::cout << d2->_name << std::endl;
    std::cout << &d2->_id << std::endl;
    std::cout << &d->_id << std::endl;
    std::cout << &d2->_name << std::endl;
    std::cout << &d->_name << std::endl;
    delete d;
    return (0);
}