#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using std::vector;
using std::list;

class PmergeMe {
	private:
		vector<int> vec;
		list<int> lst;
	public:

		PmergeMe();
		PmergeMe(char *argv[]);
		PmergeMe(const PmergeMe &other);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &other);
		void print();
		void sort_vec(); // This could be a template for vector and list 
		void sort_lst(); // They could return the time taken to sort
};