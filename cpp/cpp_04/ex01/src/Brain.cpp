/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:43:27 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/25 09:38:23 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void ) {
	std::cout << "Default Brain constructor called\n";
}

Brain::Brain( std::string ideas[100] ) {
	std::cout << "Default Brain parameterized constructor called\n";
}

Brain::Brain( Brain const &src ) {
	std::cout << "Default Brain copy constructor called\n";
	if (this != &src)
		this->ideas = src.ideas;
}

Brain::~Brain() {
	std::cout << "Default Brain destructor called\n";
}

Animal &Brain::operator=( Brain const &rhs ) {
	if (this != &rhs)
		this->ideas = rhs.ideas;
	return *this;
}
