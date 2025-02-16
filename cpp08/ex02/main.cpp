/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:14:42 by mohimi            #+#    #+#             */
/*   Updated: 2025/02/16 13:40:35 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <vector>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    s.push(42);
    s.push(21);

    std::cout << "the top: " << s.top() << std::endl;
    std::cout << "the size: " << s.size() << std::endl;
    
    std::cout << "======================== test for vector: ==================" << std::endl;
    
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(17);
    std::cout << vec.back() << std::endl;
    vec.pop_back();
    std::cout << vec.size() << std::endl;
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(737);
    vec.push_back(0);
    std::vector<int>::iterator it2 = vec.begin();
    std::vector<int>::iterator ite2 = vec.end();
    ++it2;
    --it2;
    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }

    std::vector<int> s2(vec);
    std::cout << "the size: " << s2.size() << std::endl;
    std::cout << "the begining: " << s2.front() << std::endl;
    std::cout << "the end: " <<s2.back() << std::endl;
    s2.push_back(42);;
    std::cout << "the begining: " << s2.front() << std::endl;
    std::cout << "the end: " <<s2.back() << std::endl;

    std::cout << "======================== test for list: ==================" << std::endl;

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << std::endl;
    lst.pop_back();
    std::cout << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    lst.push_front(1337);
    lst.pop_front();
    
    std::list<int>::iterator it1 = lst.begin();
    std::list<int>::iterator ite1 = lst.end();
    ++it1;
    --it1;
    while (it1 != ite1)
    {
        std::cout << *it1 << std::endl;
        ++it1;
    }
    std::list<int> s1(lst);
    std::cout << s1.size() << std::endl;
    std::cout << "the begining: " << s1.front() << std::endl;
    std::cout << "the end: " <<s1.back() << std::endl;
    s1.push_back(42);
    s1.push_front(21);
    std::cout << "the begining: " << s1.front() << std::endl;
    std::cout << "the end: " <<s1.back() << std::endl;
    return 0;
}