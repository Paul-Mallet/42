/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:54:32 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/04 12:01:44 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void ): _n(5) {
	std::cout << "Span: Default Constructor" << std::endl;
};

Span::Span( unsigned int N ): _n(N) {
	std::cout << "Span: Parametrized Constructor" << std::endl;
};

Span::Span( Span const & src ): _n(src._n) {
	std::cout << "Span: Copy Constructor" << std::endl;
};

Span::~Span() {
	std::cout << "Span: Destructor" << std::endl;
};

Span & Span::operator=( Span const & rhs ) {
	if (this != &rhs) {
		this->_n = rhs._n;
	}
	return (*this);
};

unsigned int Span::getCapacity( void ) const {
	return (this->_n);
};

std::vector<unsigned int> Span::getStorage( void ) const {
	return (this->_storage);
};

void Span::addNumber( unsigned int number ) {
	if (this->_storage.size() >= this->_n) {
		throw (SpanStorageIsFullException());
	}
	this->_storage.push_back(number);
};

unsigned int Span::shortestSpan( void ) const {
	if (this->_storage.size() <= 1)
		throw (NotEnoughNumbersStoredException());

	std::vector<unsigned int> vec_tmp = this->_storage;
	std::sort(vec_tmp.begin(), vec_tmp.end());

	unsigned int min_dist = *(vec_tmp.begin() + 1) - *vec_tmp.begin();
	for (std::vector<unsigned int>::iterator it = vec_tmp.begin(); it != (vec_tmp.end() - 1); ++it) {
		unsigned int dist = *(it + 1) - *it;
		if (dist < min_dist)
			min_dist = dist;
	}
	return (min_dist);
};

unsigned int Span::longestSpan( void ) const {
	if (this->_storage.size() <= 1)
		throw (NotEnoughNumbersStoredException());

	unsigned int max_dist = *std::max_element(this->_storage.begin(), this->_storage.end())
				- *std::min_element(this->_storage.begin(), this->_storage.end());
	return (max_dist);
};

// 10k addNumbers, use of std::vector::insert()