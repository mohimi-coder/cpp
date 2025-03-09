/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:38:24 by mohimi            #+#    #+#             */
/*   Updated: 2025/03/09 15:09:55 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <exception>
#include <utility>
#include <sys/time.h>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <cmath>

//===================colosrs ===========

#define color "\001\033[1;36m\002"
#define pos "\001\033[0;0m\002"
#define yellow "\001\033[1;33m\002"
#define grey "\001\033[1;30m\002"
#define lg "\001\033[92m\002"
#define b_italic "\001\033[1;3m\002"
#define gold "\001\033[38;5;220m\002" 
#define dark_blue "\001\033[34m\002"
#define teal "\001\033[38;5;30m\002"
#define violet "\001\033[38;5;128m\002"
#define b_ora "\001\033[1;38;5;208m\002"


class PmergeMe 
{
    private:
        std::vector<int> min_vec;
        std::deque<int> min_deq;
        static int perfect_number;
        long long start;
        long long start_deq;
        long long end_time;
        long long end_time_deq;
        static bool is_printed;
        
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
    public:
        PmergeMe();
        ~PmergeMe();

        void validateInput(int ac, char** av);
        void fillPaireVec(std::vector<std::pair<int, int> > &vec);
        void sort_pairs(std::vector<std::pair<int, int> > &vec);
        void split_pairs(std::vector<std::pair<int, int> > &vec, std::vector<int> &first_r, std::vector<int> &second_r);
        void fillData(int ac, char** av);
        std::vector<int> jacobsthal_numbers(int v);
        std::vector<std::pair<int, int> > markPosition(std::vector<int> &second_r);
        void print_before_after(std::vector<int> &first_r);
        void print_time();

        //============================ std::deque algo ============================
        void fillPaireDeque(std::deque<std::pair<int, int> > &deq);
        void sort_pairs_deque(std::deque<std::pair<int, int> > &deq);
        void split_pairs_deque(std::deque<std::pair<int, int> > &deq, std::deque<int> &first_r, std::deque<int> &second_r);
        std::deque<int> jacobsthal_numbers_deque(int deq);
        std::deque<std::pair<int, int> > markPosition_deque(std::deque<int> &second_r);
        void print_before_after_deque(std::deque<int> &first_r);
        class InvaldException : public std::exception 
        {
            public:
                const char* what() const throw();
        };
};

#endif