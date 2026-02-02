/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:27:03 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/02 18:25:51 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

/**
 * @brief Construction with no parameter: Creates an empty array.
 */
template<typename T>
Array<T>::Array( void ): _elements(NULL), _size(0) {}

/**
 * @brief Construction with an unsigned int n as a parameter:
 * Creates an array of n elements initialized by default.
 */
template<typename T>
Array<T>::Array( unsigned int n ): _elements(NULL), _size(n) {
	this->_elements = new T[n]();
}

/**
 * @brief Construction by copy.
 * Modifying either the original array or its copy after copying musn’t affect the other array.
 */
template<typename T>
Array<T>::Array( Array<T> const & src ): _elements(NULL), _size(src._size) {
	if (src._size > 0) {
		this->_elements = new T[src._size];
		for (unsigned int i = 0; i < this->_size; ++i)
			this->_elements[i] = src._elements[i];
	}
	else
		this->_elements = NULL;
}

/**
 * @brief Destruction with delete dynamic allocation memory.
 */
template<typename T>
Array<T>::~Array() {
	if (this->_elements)
		delete [] this->_elements;
}

/**
 * @brief Construction assignment operator.
 * Modifying either the original array or its copy after copying musn’t affect the other array.
 */
template<typename T>
Array<T>& Array<T>::operator=( Array<T> const & rhs ) {
	if (this != &rhs) {
		delete [] this->_elements;
		this->_size = rhs._size;
		if (this->_size > 0) {
			this->_elements = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; ++i)
				this->_elements[i] = rhs._elements[i];
		}
		else
			this->_elements = NULL;
	}
	return (*this);
}

/**
 * @brief Elements can be accessed through the subscript operator: [ ].
 */
template<typename T>
T& Array<T>::operator[]( unsigned int i ) {
	if (i >= this->_size)
		throw (OutOfBoundsIndexException()); //try catch
	return (this->_elements[i]);
}

/**
 * @brief const elements can be accessed through the subscript operator: [ ].
 */
template<typename T>
const T& Array<T>::operator[]( unsigned int i ) const {
	if (i >= this->_size)
		throw (OutOfBoundsIndexException());
	return (this->_elements[i]);
}

/**
 * @brief returns the number of elements in the array.
 */
template<typename T>
unsigned int Array<T>::size( void ) const {
	return (this->_size);
}

/**
 * @brief Exception message if [ ] operator subscript index is out of bounds.
 */
template<typename T>
const char* Array<T>::OutOfBoundsIndexException::what( void ) const throw() {
	return ("Index out of bounds");
}

#endif