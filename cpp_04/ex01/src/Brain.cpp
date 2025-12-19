/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:24:22 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/12/19 12:36:09 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void ) : _ideas() {
	std::cout << "Brain: Default Constructor" << std::endl;
}

Brain::Brain( std::string ideas[100] ) {
	(void)ideas;
	std::cout << "Brain: Parameterized Constructor" << std::endl;
}

Brain::Brain( Brain const &src ) {
	std::cout << "Brain: Copy Constructor" << std::endl;
	if (this != &src)
	{
		std::cout << "To implement" << std::endl;
	}
}

Brain::~Brain() {
	std::cout << "Brain: Destructor" << std::endl;
}

Brain &Brain::operator=( Brain const &rhs ) {
	std::cout << "Brain: Copy Assignment" << std::endl;
	if (this != &rhs)
	{
		std::cout << "To implement" << std::endl;
	}
	return (*this);
}