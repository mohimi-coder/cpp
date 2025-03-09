/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:32:07 by mohimi            #+#    #+#             */
/*   Updated: 2025/03/09 15:14:15 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

int PmergeMe::perfect_number = -1;
bool PmergeMe::is_printed = false;

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

long long getCurrentTimeMicroseconds() 
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000LL + tv.tv_usec;
}
void PmergeMe::validateInput(int ac, char** av)
{
    for (int i = 1; i < ac; i++)
    {
        char* str = av[i];
        if(!str || *str == '\0')
            throw InvaldException();
        if (*str == '-')
            throw InvaldException();
        for(char *ptr = str; *ptr; ptr++)
        {
            if (!std::isdigit(*ptr) && !(ptr == str && *ptr == '-')) 
                throw InvaldException();
        }
        char* endPtr;
        long value = std::strtol(str, &endPtr, 10);
        if (*endPtr != '\0')
            throw InvaldException();
        if (value < INT_MIN || value > INT_MAX) 
             throw InvaldException();
    }
}

const char *PmergeMe::InvaldException::what() const throw()
{
    return dark_blue "Error" pos;
}

void PmergeMe::fillData(int ac, char** av) 
{
    validateInput(ac, av);
    std::vector<std::pair<int, int> > vec;
    std::deque<std::pair<int, int> > deq;
    int numbers = 0;
    start = getCurrentTimeMicroseconds();
    for (int i = 1; i < ac; i++) 
    {
        numbers = std::atoi(av[i]);
        min_vec.push_back(numbers);
    }
    fillPaireVec(vec);
    numbers = 0;
    start_deq = getCurrentTimeMicroseconds();
    for (int i = 1; i < ac; i++)
    {
        numbers = std::atoi(av[i]);
        min_deq.push_back(numbers);
        
    }
    fillPaireDeque(deq);
    end_time_deq = getCurrentTimeMicroseconds();
    print_time();
}

void PmergeMe::fillPaireVec(std::vector<std::pair<int, int> > &vec)
{
    size_t i = 0;
    std::vector<int> first_r;
    std::vector<int> second_r;
    if (min_vec.size() == 1 || min_deq.size() == 1)
    {
        throw InvaldException();
    }
    else if(min_vec.size() % 2 != 0)
    {
        perfect_number = min_vec[0];  
        i++;
    }
    for(; i < min_vec.size(); i++)
    {
        vec.push_back(std::make_pair(min_vec[i], min_vec[i + 1]));
        i++;
    }
    for(std::vector<std::pair<int, int> >::iterator it = vec.begin(); it != vec.end(); it++)
    {
        if(it->first < it->second)
        {
            int temp = it->first;
            it->first = it->second;
            it->second = temp;
        }
    }
    sort_pairs(vec);
    split_pairs(vec, first_r, second_r);
}

void PmergeMe::sort_pairs(std::vector<std::pair<int, int> > &vec)
{
    std::sort(vec.begin(), vec.end());
}

void PmergeMe::split_pairs(std::vector<std::pair<int, int> > &vec, std::vector<int> &first_r, std::vector<int> &second_r)
{
    std::vector<int> jacob;
    std::vector<int> comb;
    std::vector<int>::iterator iter;
    std::vector<std::pair<int, int> > index;
    for(std::vector<std::pair<int, int> >::iterator it = vec.begin(); it != vec.end(); it++)
    {
        first_r.push_back(it->first);
        second_r.push_back(it->second);
    }
    first_r.insert(first_r.begin(), *(second_r.begin()));
    size_t size = min_vec.size();
    jacob = jacobsthal_numbers(size);
    size_t start = 3;
    size_t  jac_ = jacob[start];
    size_t stop = 1;
    while(jac_ < size)
    {
        while(stop < jac_)
        {
            comb.push_back(jac_);
            jac_--;
        }
        stop = jacob[start];
        jac_ = jacob[++start];
    }
    index = markPosition(second_r);
    for(size_t i = 0; i < comb.size();i++)
    {
        for(std::vector<std::pair<int, int> >::iterator it = index.begin(); it != index.end(); it++)
        {
            if(it->first == comb[i])
            {
               iter = std::lower_bound(first_r.begin(), first_r.end(), it->second);
                first_r.insert(iter, it->second);
            }
        }
    }
    if (perfect_number != -1)
    {
        iter = std::lower_bound(first_r.begin(), first_r.end(), perfect_number);
        first_r.insert(iter, perfect_number);
    }
    end_time = getCurrentTimeMicroseconds();
    print_before_after(first_r);
}

std::vector<int> PmergeMe::jacobsthal_numbers(int v)
{
    int n = 0;
    std::vector<int> jacob;
    while (true)
    {
        if (n == 0)
            jacob.push_back(0);
        else if (n == 1)
            jacob.push_back(1);
        else
            jacob.push_back(jacob[n - 1] + 2 * jacob[n - 2]);
        if (jacob[jacob.size() - 1] >= v)
            break;
        n++;
    }
    return jacob;
}

std::vector<std::pair<int, int> > PmergeMe::markPosition(std::vector<int> &second_r)
{
    std::vector<std::pair<int, int> > index;
    index.reserve(second_r.size());
    for (size_t i = 0; i < second_r.size(); i++)
        index.push_back(std::make_pair(i + 1, second_r[i]));
    return index;
}
void PmergeMe::print_before_after(std::vector<int> &first_r)
{
    std::cout << b_ora b_italic << "Before: " pos;
    for (std::vector<int>::iterator it = min_vec.begin(); it != min_vec.end(); it++)
        std::cout << b_italic << *it << pos << " ";
    std::cout << b_ora b_italic << "\nAfter: " pos;
    for (std::vector<int>::iterator it = first_r.begin(); it != first_r.end(); it++)
        std::cout << b_italic << *it << pos << " ";
    std::cout << std::endl;
    is_printed = true;
}


//============================ std::deque algo ============================

void PmergeMe::fillPaireDeque(std::deque<std::pair<int, int> > &deq)
{
    size_t i = 0;
    std::deque<int> first_r;
    std::deque<int> second_r;
    if (min_vec.size() == 1 || min_deq.size() == 1)
    {
        throw InvaldException();
    }
    else if(min_deq.size() % 2 != 0)
    {
        perfect_number = min_deq[0];  
        i++;
    }
    for(; i < min_deq.size(); i++)
    {
        deq.push_back(std::make_pair(min_deq[i], min_deq[i + 1]));
        i++;
    }
    for(std::deque<std::pair<int, int> >::iterator it = deq.begin(); it != deq.end(); it++)
    {
        if(it->first < it->second)
        {
            int temp = it->first;
            it->first = it->second;
            it->second = temp;
        }
    }
    sort_pairs_deque(deq);
    split_pairs_deque(deq, first_r, second_r);
}

void PmergeMe::sort_pairs_deque(std::deque<std::pair<int, int> > &deq)
{
    std::sort(deq.begin(), deq.end());
}

void PmergeMe::split_pairs_deque(std::deque<std::pair<int, int> > &deq, std::deque<int> &first_r, std::deque<int> &second_r)
{
    std::deque<int> jacob;
    std::deque<int> comb;
    std::deque<int>::iterator iter;
    std::deque<std::pair<int, int> > index;
    for(std::deque<std::pair<int, int> >::iterator it = deq.begin(); it != deq.end(); it++)
    {
        first_r.push_back(it->first);
        second_r.push_back(it->second);
    }
    first_r.insert(first_r.begin(), *(second_r.begin()));
    size_t size = min_deq.size();
    jacob = jacobsthal_numbers_deque(size);
    size_t start = 3;
    size_t  jac_ = jacob[start];
    size_t stop = 1;
    while(jac_ < size)
    {
        while(stop < jac_)
        {
            comb.push_back(jac_);
            jac_--;
        }
        stop = jacob[start];
        jac_ = jacob[++start];
    }
    index = markPosition_deque(second_r);
    for(size_t i = 0; i < comb.size();i++)
    {
        for(std::deque<std::pair<int, int> >::iterator it = index.begin(); it != index.end(); it++)
        {
            if(it->first == comb[i])
            {
               iter = std::lower_bound(first_r.begin(), first_r.end(), it->second);
                first_r.insert(iter, it->second);
            }
        }
    }
    if (perfect_number != -1)
    {
        iter = std::lower_bound(first_r.begin(), first_r.end(), perfect_number);
        first_r.insert(iter, perfect_number);
    }
    if (is_printed == false)
        print_before_after_deque(first_r);
}

void PmergeMe::print_before_after_deque(std::deque<int> &first_r)
{
    std::cout << b_ora b_italic << "Before: " pos;
    for (std::deque<int>::iterator it = min_deq.begin(); it != min_deq.end(); it++)
        std::cout << b_italic << *it << pos << " ";
    std::cout << b_ora b_italic << "\nAfter: " pos;
    for (std::deque<int>::iterator it = first_r.begin(); it != first_r.end(); it++)
        std::cout << b_italic << *it << pos << " ";
    std::cout << std::endl;
}

std::deque<int> PmergeMe::jacobsthal_numbers_deque(int deq)
{
    int n = 0;
    std::deque<int> jacob;
    while (true)
    {
        if (n == 0)
            jacob.push_back(0);
        else if (n == 1)
            jacob.push_back(1);
        else
            jacob.push_back(jacob[n - 1] + 2 * jacob[n - 2]);
        if (jacob[jacob.size() - 1] >= deq)
            break;
        n++;
    }
    return jacob;
}

std::deque<std::pair<int, int> > PmergeMe::markPosition_deque(std::deque<int> &second_r)
{
    std::deque<std::pair<int, int> > index;
    for (size_t i = 0; i < second_r.size(); i++)
        index.push_back(std::make_pair(i + 1, second_r[i]));
    return index;
}

void PmergeMe::print_time()
{
    std::cout << std::fixed << std::setprecision(3) << gold b_italic "Time to process a range of " pos << b_italic << min_vec.size() << pos <<color b_italic " elements with std::vector : " pos << b_italic << end_time - start<< pos << lg b_italic << " us" << pos << std::endl;
    std::cout << std::fixed << std::setprecision(3) << gold b_italic "Time to process a range of " pos << b_italic << min_deq.size() << pos << color b_italic " elements with std::deque : " pos << b_italic << end_time_deq - start_deq << pos<< lg b_italic << " us" << pos << std::endl;
}