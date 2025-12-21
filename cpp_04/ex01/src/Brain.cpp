/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:24:22 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/12/21 10:20:57 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void ) {
	std::cout << "Brain: Default Constructor" << std::endl;
	this->ideas[0] = "...";
}

Brain::Brain( std::string idea ) {
	std::cout << "Brain: Parameterized Constructor" << std::endl;
	this->ideas[0] = idea;
}

Brain::Brain( Brain const &src ) {
	std::cout << "Brain: Copy Constructor" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < MAX_IDEAS; i++)
			this->ideas[i] = src.ideas[i];
	}
}

Brain::~Brain() {
	std::cout << "Brain: Destructor" << std::endl;
}

Brain &Brain::operator=( Brain const &rhs ) {
	std::cout << "Brain: Copy Assignment" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < MAX_IDEAS; i++)
			this->ideas[i] = rhs.ideas[i];
	}
	return (*this);
}