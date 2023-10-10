#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {};

PmergeMe::~PmergeMe() {};

PmergeMe::PmergeMe(PmergeMe const &other) {
	*this = other;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other) {
	if (this != &other) {
		this->vec = other.vec;
		this->lst = other.lst;
	}
	return *this;
}

PmergeMe::PmergeMe(char *argv[]) {
	for (int i = 1; argv[i]; i++) {
		int tmp = std::atoi(argv[i]);
		if (tmp < 0 || std::strcmp(argv[i], "-0") == 0)
			throw std::invalid_argument("Negative number not allowed");
		vec.push_back(tmp);
		lst.push_back(tmp);
	}
}

// $> ./PmergeMe 3 5 9 7 4 
// Before: 35974
// After: 34579
// Time to process a range of 5 elements with std::[..] : 0.00031 us
// Time to process a range of 5 elements with std::[..] : 0.00014 us $> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
// Before:  141 79 526 321 [...]
// After:   79 141 321 526 [...]
// Time to process a range of 3000 elements with std::[..] : 62.14389 us
// Time to process a range of 3000 elements with std::[..] : 69.27212 us
// $> ./PmergeMe "-1" "2"
// Error
// $> # For OSX USER:
// $> ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
// [...]
// $>

void PmergeMe::print() {
	std::cout << "Before: ";
	vector<int>::iterator it = vec.begin();
	for (; it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "After: " << std::endl;
}

void PmergeMe::sort_vec() {

	 // Instead of storing it in a vec why not store them in pairs in the constrcutro?
	std::vector<std::pair<int, int> > pairs; // Declaring a vector of pairs

	// Step 1. Store the num. in pairs of 2;
	for (size_t i = 0; i < vec.size(); i += 2) {
		if (i + 1 < vec.size()) // If
			pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
	}

	// Step 2: Swap numbers so that the first element is the smaller one
	for (size_t i = 0; i < pairs.size(); ++i) {
		if (pairs[i].first > pairs[i].second)
			std::swap(pairs[i].first, pairs[i].second);
	}

	// Step 3: Seperate the smaller elements and the bigger elements in the pairs into two vecs
	std::vector<int> elementsInFirst;
	std::vector<int> elementsInSecond;

	std::vector<std::pair<int, int> >::const_iterator itPair;
	for (itPair = pairs.begin(); itPair != pairs.end(); ++itPair) {
		elementsInFirst.push_back(itPair->first);
		elementsInSecond.push_back(itPair->second);
	}

	// Step 3.1: Sort the elements in incresing order
	std::sort(elementsInFirst.begin(), elementsInFirst.end());
	std::sort(elementsInSecond.begin(), elementsInSecond.end());

	// Step 4: Inserting the elementsInSecond into elementsInFirst
	std::vector<int>::const_iterator it;
	for (it = elementsInSecond.begin(); it != elementsInSecond.end(); ++it) {
		std::vector<int>::iterator pos = std::upper_bound(elementsInFirst.begin(), elementsInFirst.end(), *it);
		elementsInFirst.insert(pos, *it);
	}

	// Step 5. Handle the unpaired element if the size of vec is odd
	if (vec.size() % 2 != 0) {
		int oddElement = vec.back();
		std::vector<int>::iterator pos = std::upper_bound(elementsInFirst.begin(), elementsInFirst.end(), oddElement);
		elementsInFirst.insert(pos, oddElement);
	}
}

void	PmergeMe::sort_lst() {
	std::list<std::make_pair<int, int> > pairs;
}



