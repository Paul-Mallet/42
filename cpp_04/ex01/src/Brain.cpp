/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:24:22 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/12/19 18:28:49 by pamallet         ###   ########.fr       */
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

// #TODO !!!
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

// #TODO !!!
Brain &Brain::operator=( Brain const &rhs ) {
	std::cout << "Brain: Copy Assignment" << std::endl;
	if (this != &rhs)
	{
		std::cout << "To implement" << std::endl;
	}
	return (*this);
}
