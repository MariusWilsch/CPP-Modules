#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <chrono>

using std::vector;
using std::list;

class PmergeMe {
	private:
		vector<int> vec;
		list<int> lst;
		std::array<std::chrono::microseconds, 2> duration;
	public:

		PmergeMe();
		PmergeMe(char *argv[]);
		PmergeMe(const PmergeMe &other);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &other);
		void printResult();
		void sort_vec(); // This could be a template for vector and list 
		void sort_lst(); // They could return the time taken to sort
};