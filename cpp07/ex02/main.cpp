/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 21:22:13 by mohimi            #+#    #+#             */
/*   Updated: 2025/02/08 14:48:04 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

class Person 
{
    public:
        std::string _name;
        int _age;
        Person(std::string name = "", int age = 0) : _name(name), _age(age) {}

        void print() const 
        {
            std::cout << "Name: " << _name << ", Age: " << _age << std::endl;
        }
};

int main()
{
    try
    {
        Array<int> arr2(5);
        Array<double> arr1(4);
        Array<std::string> arr5(3);

        arr5[0] = "Hello";
        arr5[1] = "World";
        arr5[2] = "!";
        
        for (size_t i = 0; i < arr5.size(); i++)
            std::cout << arr5[i] << " ";
        std::cout << std::endl;

        std::cout << "================Testing basic types:================\n";
        
        for (size_t i = 0; i < arr2.size(); i++)
            arr2[i] = i * 2;

        for (size_t i = 0; i < arr1.size(); i++)
        {
            arr1[i] = i * 3;
            std::cout << "arr1: " << arr1[i] << std::endl;
        }
        
        Array<double> arr4(arr1);

        arr4[2] = 42;

        std::cout << "arr4[1]: " << arr4[1] << std::endl;
        std::cout << "arr4 size: " << arr4.size() << std::endl;
        for (size_t i = 0; i < arr4.size(); i++)
            std::cout << arr4[i] << " ";
        std::cout << std::endl;
        
        Array<int> arr3(0);

        std::cout << "arr3 size (empty array): " << arr3.size() << std::endl;

        arr3 = arr2;
        
        for (size_t i = 0; i < arr3.size(); i++)
            std::cout << arr3[i] << " ";
        std::cout << std::endl;
        
        arr3[2] = 1337;
        std::cout << "arr3[2]: " << arr3[2] << std::endl;
        std::cout << "arr2[2]: " << arr2[1] << std::endl;
        
        std::cout << "arr3 size: " << arr3.size() << std::endl;

        Array<Person> personArray(3);

        personArray[0] = Person("Alice", 25);
        personArray[1] = Person("Bob", 30);
        personArray[2] = Person("Charlie", 35);

        std::cout << "\n===============Testing complex type (Person):==============\n";
        
        for (size_t i = 0; i < personArray.size(); i++) 
            personArray[i].print();
        
        std::cout << arr3[10] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}
