/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:32:34 by verdant           #+#    #+#             */
/*   Updated: 2023/08/08 12:30:10 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*			Orthodox Canonical Form			*/

SortContainers::SortContainers( void ) {};

SortContainers::SortContainers( char** argv ) {
	high_resolution_clock::time_point start;
	cout << "Before: ";
	for (int i = 1; argv[i]; i++) {
		if (isdigit(argv[i][0])) {
			int n = atoi(argv[i]);
			cout << n << " ";
			_vec.push_back(n);
			_deq.push_back(n);
		}
		else 
			throw std::invalid_argument("Invalid argument");
	}
	cout << endl;
	
	start = high_resolution_clock::now();
	SortContainers::mergeSortVec(_vec, _vec.size());
	_durationVec = std::chrono::duration_cast<std::chrono::microseconds>(high_resolution_clock::now() - start);
	
	start = high_resolution_clock::now();
	SortContainers::mergeSortDeque(_deq, _deq.size());
	_durationDeq = std::chrono::duration_cast<std::chrono::microseconds>(high_resolution_clock::now() - start);
	printResult();
};

SortContainers::~SortContainers( void ) {};

SortContainers::SortContainers( const SortContainers& src) : _vec(src._vec) {};

SortContainers& SortContainers::operator=(const SortContainers& src) {
	if (this == &src)
		return *this;
	_vec = src._vec;
	return *this;
}

/*			 Member Functions			*/

void	SortContainers::printResult( void )
{
	cout << "After: ";
	for (deque<int>::iterator it = _deq.begin(); it != _deq.end(); it++)
		cout << *it << " ";
	cout << endl;
	// Time to process a range of 5 elements with std::[..] : 0.00031 us
	cout << "Time to process a range of " << _vec.size() << " elements with std::vector<int> : " <<  _durationVec.count() << " us" << endl;
	cout << "Time to process a range of " << _deq.size() << " elements with std::deque<int> : " <<  _durationDeq.count() << " us" << endl;
}

void	SortContainers::mergeVec(vector<int> &left, vector<int> &right, vector<int> &vec)
{
	int	leftSize, rightSize, i, l, r;

	leftSize = left.size(); 
	rightSize = right.size();
	i = l = r = 0;

	while (l < leftSize && r < rightSize) {
		if (left[l] < right[r])
			vec[i++] = left[l++];
		else
			vec[i++] = right[r++];
	}
	while (l < leftSize)
		vec[i++] = left[l++];
	while (r < rightSize)
		vec[i++] = right[r++];
}

void	SortContainers::mergeSortVec(vector<int> &vec, int len)
{
	int	mid;

	if (len < 2)
		return ;
	mid = len / 2;
	vector<int> left(vec.begin(), vec.begin() + mid);
	vector<int> right(vec.begin() + mid, vec.end());
	mergeSortVec(left, left.size());
	mergeSortVec(right, right.size());
	mergeVec(left, right, vec);
}

void	SortContainers::mergeSortDeque(deque<int> &deq, int len)
{
	if (len < 2)
		return ;
	int mid = len / 2;
	deque<int> left(deq.begin(), deq.begin() + mid);
	deque<int> right(deq.begin() + mid, deq.end());
	mergeSortDeque(left, left.size());
	mergeSortDeque(right, right.size());
	mergeDeque(left, right, deq);
}

void	SortContainers::mergeDeque(deque<int> &left, deque<int> &right, deque<int> &deq)
{
	int	leftSize, rightSize, i, l, r;

	leftSize = left.size(); 
	rightSize = right.size();
	i = l = r = 0;

	while (l < leftSize && r < rightSize) {
		if (left[l] < right[r])
			deq[i++] = left[l++];
		else
			deq[i++] = right[r++];
	}
	while (l < leftSize)
		deq[i++] = left[l++];
	while (r < rightSize)
		deq[i++] = right[r++];
}
