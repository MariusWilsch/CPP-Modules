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
	std::cout << "Before ";
	std::vector<int>::iterator it;
	for (it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	sort_lst();
	sort_vec();

	std::cout << "After ";
	for (it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	// TODO: Time is represented wrongly
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vec : " << duration[0].count() << " us" << std::endl;
	std::cout << "Time to process a range of " << lst.size() << " elements with std::lst : " << duration[1].count() << " us" << std::endl;
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

void PmergeMe::printResult() {
	
}

void PmergeMe::sort_vec() {

	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

	 //FIXME: Instead of storing it in a vec why not store them in pairs in the constrcutro?
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

	duration[0] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start);

	// Copy the sorted elements back to vec
	vec = elementsInFirst;

}

void	PmergeMe::sort_lst() {


	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

	 // Instead of storing it in a vec why not store them in pairs in the constrcutro?
	std::list<std::pair<int, int> > pairs; // Declaring a vector of pairs

	// Step 1. Store the num. in pairs of 2;
	// for (size_t i = 0; i < vec.size(); i += 2) {
	// 	if (i + 1 < vec.size()) 
	// 		pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
	// }

	std::list<int>::iterator it;
	std::list<int>::iterator itNext;

	for (it = lst.begin(); it != lst.end(); std::advance(it, 2)) {
		itNext = it;
		++itNext;
		if (itNext != lst.end()) {
			pairs.push_back(std::make_pair(*it, *itNext));
		}
	}

	// Step 2: Swap numbers so that the first element is the smaller one
	// for (size_t i = 0; i < pairs.size(); ++i) {
	// 	if (pairs[i].first > pairs[i].second)
	// 		std::swap(pairs[i].first, pairs[i].second);
	// }


	for (std::list<std::pair<int, int > >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}


	// // Step 3: Seperate the smaller elements and the bigger elements in the pairs into two vecs
	std::list<int> elementsInFirst;
	std::list<int> elementsInSecond;

	// std::vector<std::pair<int, int> >::const_iterator itPair;
	// for (itPair = pairs.begin(); itPair != pairs.end(); ++itPair) {
	// 	elementsInFirst.push_back(itPair->first);
	// 	elementsInSecond.push_back(itPair->second);
	// }

	for (std::list<std::pair<int ,int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
		elementsInFirst.push_back(it->first);
		elementsInSecond.push_back(it->second);
	}

	// // Step 3.1: Sort the elements in incresing order
	elementsInFirst.sort();
	elementsInSecond.sort();

	// // Step 4: Inserting the elementsInSecond into elementsInFirst
	// std::vector<int>::const_iterator it;
	// for (it = elementsInSecond.begin(); it != elementsInSecond.end(); ++it) {
	// 	std::vector<int>::iterator pos = std::upper_bound(elementsInFirst.begin(), elementsInFirst.end(), *it);
	// 	elementsInFirst.insert(pos, *it);
	// }

	for (std::list<int>::const_iterator it = elementsInSecond.begin(); it != elementsInSecond.end(); ++it)
		elementsInFirst.insert(std::upper_bound(elementsInFirst.begin(), elementsInFirst.end(), *it), *it);

	// Step 5. Handle the unpaired element if the size of vec is odd

	// if (vec.size() % 2 != 0) {
	// 	int oddElement = vec.back();
	// 	std::vector<int>::iterator pos = std::upper_bound(elementsInFirst.begin(), elementsInFirst.end(), oddElement);
	// 	elementsInFirst.insert(pos, oddElement);
	// }

		if (lst.size() % 2 != 0)
			elementsInFirst.insert(std::upper_bound(elementsInFirst.begin(), elementsInSecond.end(), lst.back()), lst.back());

	duration[1] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start);

	// Copy the sorted elements back to lst

	lst = elementsInFirst;

}



