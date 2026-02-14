/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:17:46 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/14 11:41:25 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void ) : _vectorChrono(0), _dequeChrono(0), _isSorted(false) {}

PmergeMe::PmergeMe( PmergeMe const & src ):
	_vectorChrono(src._vectorChrono),
	_dequeChrono(src._dequeChrono),
	_isSorted(src._isSorted) {}

PmergeMe::~PmergeMe() {}

PmergeMe & PmergeMe::operator=( PmergeMe const & rhs ) {
	if (this != &rhs) {
		this->_vectorNumbers = rhs._vectorNumbers;
		this->_vectorChrono = rhs._vectorChrono;
		this->_dequeChrono = rhs._dequeChrono;
		this->_isSorted = rhs._isSorted;
	}
	return (*this);
}

std::vector<int> PmergeMe::getVectorNumbers( void ) const {
	return (this->_vectorNumbers);
}

std::deque<int> PmergeMe::getDequeNumbers( void ) const {
	return (this->_dequeNumbers);
}

double PmergeMe::getVectorChrono( void ) const {
	return (this->_vectorChrono);
}

double PmergeMe::getDequeChrono( void ) const {
	return (this->_dequeChrono);
}

bool PmergeMe::getSorted( void ) const {
	return (this->_isSorted);
}

void PmergeMe::evaluate( int ac, char ** av ) {
	/**
	 * @brief Parse arguments (av) to assess characters other than digits and space.
	 */
	std::string numStr = "";

	for(int i = 1; i < ac; ++i) {
		numStr += av[i];
		if (i + 1 != ac)
			numStr += " ";
	}
	if (numStr.find_first_not_of("0123456789 ") != std::string::npos)
		throw (NotPositiveIntegerFoundException());

	/**
	 * @brief Convert into positive integers and store them into the PmergeMe storage private attribute.
	 */
	std::stringstream	ss(numStr);
	std::string			digit;
	long				val;

	while (ss >> digit) {
		val = atol(digit.c_str());
		if (val > std::numeric_limits<int>::max())
			throw (OverflowIntegerException());
		this->_vectorNumbers.push_back(static_cast<int>(val));
		this->_dequeNumbers.push_back(static_cast<int>(val));
	}

	/**
	 * @brief Display unsorted numbers only once.
	 */
	this->display(this->_vectorNumbers);

	/**
	 * @brief Wrap fordJohnson while recording time to sort with a vector and deque containers.
	 */
	this->_vectorChrono = this->processTimeVector();
	this->_dequeChrono = this->processTimeDeque();
	this->_isSorted = true;

	/**
	 * @brief Numbers sorted based on the Ford-Johnson main chain.
	 */
	this->display(this->_vectorNumbers);

	/**
	 * @brief Display time spent to compute with each containers.
	 */
	this->displayVectorProcessTime();
	this->displayDequeProcessTime();
}


/**
 * @brief Time to process a std::vector range of numbers.
 */
double PmergeMe::processTimeVector( void ) {
	struct timeval start, end;

	gettimeofday(&start, NULL);
	this->fordJohnsonVector(this->_vectorNumbers);
	gettimeofday(&end, NULL);

	long sec = end.tv_sec - start.tv_sec;
	long usec = end.tv_usec - start.tv_usec;
	return (sec * 1000000 + usec);
}

/**
 * @brief Time to process a std::deque range of numbers.
 */
double PmergeMe::processTimeDeque( void ) {
	struct timeval start, end;

	gettimeofday(&start, NULL);
	this->fordJohnsonDeque(this->_dequeNumbers);
	gettimeofday(&end, NULL);

	long sec = end.tv_sec - start.tv_sec;
	long usec = end.tv_usec - start.tv_usec;
	return (sec * 1000000 + usec);
}

/**
 * @brief Display unsorted std::vector.
 */
void PmergeMe::display( std::vector<int> ctnr ) {
	int i = 0;
	int limit = 5;

	if (!this->_isSorted)
		std::cout << std::left << std::setw(10) << "Before: ";
	else
		std::cout << std::left << std::setw(10) << "After: ";
	for (std::vector<int>::iterator it = ctnr.begin(); it != ctnr.end(); ++it) {
		if (!(i < limit)) {
			std::cout << "[...]";
			break ;
		}
		std::cout << *it;
		if (it + 1 != ctnr.end()) 
			std::cout << " ";
		++i;
	}
	std::cout << std::endl;
}

/**
 * @brief Merge-sort algorithm with a vector container.
 * @param winners _main containing pair winners without potential straggler.
 * @warning 1rst call param is the unsorted _vectorNumbers attribute.
 */
void PmergeMe::fordJohnsonVector( std::vector<int> & numbers ) {

	if (numbers.size() < 2)
		return ;

	/**
	 * @brief Extract straggler if odd numbers.
	 */
	bool hasStraggler = false;
	int straggler = 0;
	if (numbers.size() % 2 == 1) {
		hasStraggler = true;
		straggler = numbers.back();
		numbers.pop_back();
	}

	std::vector< std::pair<int, int> > pairs;
	for (size_t i = 0; i < numbers.size(); i += 2)
		pairs.push_back( std::make_pair(numbers[i], numbers[i + 1]) );

	/**
	 * @brief Swap to have winner at pair->second.
	 */
	for (std::vector< std::pair <int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
		if (it->first > it->second)
			std::swap(it->first, it->second);

	/**
	 * @brief Extract winners into main chain.
	 */
	std::vector<int> main;
	for (std::vector< std::pair <int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
		main.push_back(it->second);
	}

	/**
	 * @brief Sort winners in ascending order while keeping link with losers.
	 */
	fordJohnsonVector(main);

	/**
	 * @brief Create pend based on sorted main chain.
	 */
	std::vector<int> pend;
	for (std::vector<int>::iterator it = main.begin(); it != main.end(); ++it) {
		for (std::vector< std::pair<int, int> >::iterator itp = pairs.begin(); itp != pairs.end(); ++itp) {
			if (itp->second == *it) {
				pend.push_back(itp->first);
				break ;
			}
		}
	}

	/**
	 * @brief Instant insert first pend loser into main chain.
	 */
	main.insert(main.begin(), pend[0]);

	/**
	 * @brief Use of Jacobsthal sequence + Binary Search to insert losers in already sorted main chain.
	 */
	std::vector<int> jOrder;
	jOrder = this->generateInsertionOrder(pend.size());
	for (size_t i = 0; i < jOrder.size(); ++i) {
		if (jOrder[i] == 0)
			continue ;
		std::vector<int>::iterator it = std::lower_bound(main.begin(), main.end(), pend[jOrder[i]]);
		main.insert(it, pend[jOrder[i]]);
	}

	/**
     * @brief Reinsert the stragger of the current recursion stage.
     */
    if (hasStraggler) {
        std::vector<int>::iterator it = std::lower_bound(main.begin(), main.end(), straggler);
        main.insert(it, straggler);
    }

	/**
	 * @brief numbers updated according to main chain.
	 */
	numbers = main;
}


/**
 * @brief Merge-sort algorithm with a deque container.
 * @param winners _main containing pair winners without potential straggler.
 * @warning 1rst call param is the unsorted _dequeNumbers attribute.
 */
void PmergeMe::fordJohnsonDeque( std::deque<int> & numbers ) {

	if (numbers.size() < 2)
		return ;

	/**
	 * @brief Extract straggler if odd numbers.
	 */
	bool hasStraggler = false;
	int straggler = 0;
	if (numbers.size() % 2 == 1) {
		hasStraggler = true;
		straggler = numbers.back();
		numbers.pop_back();
	}

	std::deque< std::pair<int, int> > pairs;
	for (size_t i = 0; i < numbers.size(); i += 2)
		pairs.push_back( std::make_pair(numbers[i], numbers[i + 1]) );

	/**
	 * @brief Swap to have winner at pair->second.
	 */
	for (std::deque< std::pair <int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
		if (it->first > it->second)
			std::swap(it->first, it->second);

	/**
	 * @brief Extract winners into main chain.
	 */
	std::deque<int> main;
	for (std::deque< std::pair <int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
		main.push_back(it->second);
	}

	/**
	 * @brief Sort winners in ascending order while keeping link with losers.
	 */
	fordJohnsonDeque(main);

	/**
	 * @brief Create pend based on sorted main chain.
	 */
	std::vector<int> pend;
	for (std::deque<int>::iterator it = main.begin(); it != main.end(); ++it) {
		for (std::deque< std::pair<int, int> >::iterator itp = pairs.begin(); itp != pairs.end(); ++itp) {
			if (itp->second == *it) {
				pend.push_back(itp->first);
				break ;
			}
		}
	}

	/**
	 * @brief Instant insert first pend loser into main chain.
	 */
	main.insert(main.begin(), pend[0]);

	/**
	 * @brief Use of Jacobsthal sequence + Binary Search to insert losers in already sorted main chain.
	 */
	std::vector<int> jOrder;
	jOrder = this->generateInsertionOrder(pend.size());
	for (size_t i = 0; i < jOrder.size(); ++i) {
		if (jOrder[i] == 0)
			continue ;
		std::deque<int>::iterator it = std::lower_bound(main.begin(), main.end(), pend[jOrder[i]]);
		main.insert(it, pend[jOrder[i]]);
	}

	/**
     * @brief Reinsert the stragger of the current recursion stage.
     */
    if (hasStraggler) {
        std::deque<int>::iterator it = std::lower_bound(main.begin(), main.end(), straggler);
        main.insert(it, straggler);
    }

	/**
	 * @brief numbers updated according to main chain.
	 */
	numbers = main;
}

/**
 * @brief Generate the insertion order of the pend list.
 *
 * @param n this->pend container size.
 * @return A jacobsthal numbers reverse groups dynamic array.
 */
std::vector<int> PmergeMe::generateInsertionOrder( int n ) {
	std::vector<int> jacob;
	std::vector<int> order;

	jacob.push_back(1);
	jacob.push_back(3);
	int next;
	while (jacob.back() < n) {
		next = jacob[jacob.size() - 1] + (2 * jacob[jacob.size() - 2]);
		jacob.push_back(next);
	}

	int curr_jacob = 0;
	int last_jacob = 1;
	int start;
    for (size_t i = 1; i < jacob.size(); ++i) {
        curr_jacob = jacob[i];
		if (curr_jacob > n)
			start = n;
		else
			start = curr_jacob;
        for (int j = start; j > last_jacob; --j)
            order.push_back(j - 1);
        last_jacob = curr_jacob;
        if (last_jacob >= n)
			break ;
    }
    return (order);
}

/**
 * @brief Display the time spent for std::vector to compute Ford-Johnson algorithm.
 * @todo Templates display
 */
void PmergeMe::displayVectorProcessTime( void ) {
	std::cout << "Time to process a range of " << this->_vectorNumbers.size()
				<< " elements with std::vector : " << this->_vectorChrono << " us" << std::endl;
}

/**
 * @brief Display the time spent for std::vector to compute Ford-Johnson algorithm.
 * @todo Templates display
 */
void PmergeMe::displayDequeProcessTime( void ) {
	std::cout << "Time to process a range of " << this->_dequeNumbers.size()
				<< " elements with std::deque : " << this->_dequeChrono << " us" << std::endl;
}

/**
 * @brief Error handling custom exceptions.
 */
const char * PmergeMe::NotPositiveIntegerFoundException::what( void ) const throw() {
	return ("Not positive integer found");
}

const char * PmergeMe::OverflowIntegerException::what( void ) const throw() {
	return ("Overflow integer");
}

std::ostream & operator<<( std::ostream & o, PmergeMe const & p ) {
	o << "vector chrono: " << p.getVectorChrono() << " us"
		<< "\ndeque chrono: " << p.getDequeChrono() << " us"
		<< "\nis sorted? : " << p.getSorted();
	return (o);
}