/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:43:27 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/26 08:36:59 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void ) {
	std::cout << "Default Brain constructor called\n";
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = "";
}

Brain::Brain( std::string ideas[100] ) {
	std::cout << "Default Brain parameterized constructor called\n";
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = ideas[i];
}

Brain::Brain( Brain const &src ) {
	std::cout << "Default Brain copy constructor called\n";
	if (this != &src)
		for (int i = 0; i < 100; ++i)
			this->ideas[i] = src.ideas[i];
}

Brain::~Brain() {
	std::cout << "Default Brain destructor called\n";
}

Brain &Brain::operator=( Brain const &rhs ) {
	if (this != &rhs)
		for (int i = 0; i < 100; ++i)
			this->ideas[i] = rhs.ideas[i];
	return *this;
}
