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
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	sort_lst();
	sort_vec();
	printResult();
}

void PmergeMe::printResult() {

	std::cout <<std::endl << std::endl << "After ";
	std::cout << vec[0] << " ";
	for (size_t i = 1; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
		if (vec[i] == vec[i - 1]) // Comment this line to see the difference in the time taken to sort
			throw std::runtime_error("Duplicate number found");
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vec.size() << " elements with std::vec : " << duration[0].count() << " us" << std::endl;
	std::cout << "Time to process a range of " << lst.size() << " elements with std::lst : " << duration[1].count() << " us" << std::endl;
}

void PmergeMe::sort_vec() {

	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

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

	 //TODO: Instead of storing it in a vec why not store them in pairs in the constrcutro?
	std::list<std::pair<int, int> > pairs; // Declaring a vector of pairs

	std::list<int>::iterator it;
	std::list<int>::iterator itNext;

	int	oddElement;

	// Step 0: Handle the unpaired element if the size of vec is odd
	if (lst.size() % 2 != 0) {
		oddElement = lst.back();
		lst.pop_back();
	}

	// Step 1. Store the num. in pairs of 2;
	for (it = lst.begin(); it != lst.end(); std::advance(it, 2)) {
		itNext = it;
		++itNext;
		if (itNext != lst.end()) {
			pairs.push_back(std::make_pair(*it, *itNext));
		}
	}

	// Step 2: Swap numbers so that the first element is the smaller one
	for (std::list<std::pair<int, int > >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}


	// Step 3: Seperate the smaller elements and the bigger elements in the pairs into two vecs
	std::list<int> elementsInFirst;
	std::list<int> elementsInSecond;

	for (std::list<std::pair<int ,int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
		elementsInFirst.push_back(it->first);
		elementsInSecond.push_back(it->second);
	}

	// Step 3.1: Sort the elements in incresing order
	elementsInFirst.sort();
	elementsInSecond.sort();

	// Step 4: Inserting the elementsInSecond into elementsInFirst
	for (std::list<int>::const_iterator it = elementsInSecond.begin(); it != elementsInSecond.end(); ++it)
		elementsInFirst.insert(std::upper_bound(elementsInFirst.begin(), elementsInFirst.end(), *it), *it);

	// Step 5. Handle the unpaired element if the size of vec is odd
	if (lst.size() % 2 != 0)
		elementsInFirst.insert(std::upper_bound(elementsInFirst.begin(), elementsInFirst.end(), oddElement), oddElement);

	duration[1] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start);

	// Copy the sorted elements back to lst
	lst = elementsInFirst;
}



