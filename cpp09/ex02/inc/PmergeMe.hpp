/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:58:50 by verdant           #+#    #+#             */
/*   Updated: 2023/08/08 12:20:54 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <chrono>
#include <algorithm>

using std::vector;
using std::deque;
using std::cout;
using std::endl;
using std::chrono::high_resolution_clock;



class SortContainers {
	private:
		std::vector<int> _vec;
		std::deque<int> _deq;
		std::chrono::microseconds _durationVec;
		std::chrono::microseconds _durationDeq;
	public:
		
		/* Orthodox Canonical Form */
		
		SortContainers( void );
		SortContainers( char** argv );
		~SortContainers( void );
		SortContainers( const SortContainers& src);
		SortContainers& operator=(const SortContainers& src);
		
		/*  Static Member Functions */
	
		static void		mergeSortVec(vector<int> &vec, int len);
		static void		mergeVec(vector<int> &left, vector<int> &right, vector<int> &vec);
		static void		mergeSortDeque(std::deque<int> &deq, int len);
		static void		mergeDeque(std::deque<int> &left, std::deque<int> &right, std::deque<int> &deq);
		
		/*  Member Functions */
		
		void		printResult(void);
};