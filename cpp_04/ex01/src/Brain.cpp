/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:24:22 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/12/19 19:33:59 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// TODO : incrementer, reset to [0]
Brain::Brain( void ) {
	std::cout << "Brain: Default Constructor" << std::endl;
	this->_ideas[0] = "...";
}

Brain::Brain( std::string idea ) {
	std::cout << "Brain: Parameterized Constructor" << std::endl;
	this->_ideas[0] = idea;
}

Brain::Brain( Brain const &src ) {
	std::cout << "Brain: Copy Constructor" << std::endl;
	if (this != &src)
	{
		int	i = 0;
		while (i < 100)
		{
			this->_ideas[i] = src._ideas[i];
			i++;
		}
	}
}

Brain::~Brain() {
	std::cout << "Brain: Destructor" << std::endl;
}

Brain &Brain::operator=( Brain const &rhs ) {
	std::cout << "Brain: Copy Assignment" << std::endl;
	if (this != &rhs)
	{
		int	i = 0;
		while (i < 100)
		{
			this->_ideas[i] = rhs._ideas[i];
			i++;
		}
	}
	return (*this);
}

std::string const Brain::getIdea( unsigned int i ) {
	if (i < 0 || i > 100)
		std::cout << "Invalid index, only 0 to 99 range accept" << std::endl;
	return (this->_ideas[i]);
}

void const Brain::setIdea( std::string idea ) {
	this->_ideas[this->_inc] = idea;
	if ((this->_inc + 1) < 100)
		this->_inc++;
	else
		this->_inc = 0;
}