/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:56:24 by pamallet          #+#    #+#             */
/*   Updated: 2025/09/01 17:57:44 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include "../includes/ICharacter.hpp"

AMateria::AMateria( void ) : type("material") {
	std::cout << "AMateria default constructor called\n";
}

AMateria::AMateria( std::string const &type ) : type(type) {
	std::cout << "AMateria parameterized constructor called\n";
}

AMateria::AMateria( AMateria const &src ) {
	std::cout << "AMateria copy constructor called\n";
	if (this != &src)
		this->type = src.type;
}

AMateria::~AMateria() {
	std::cout << "AMateria destructor called\n";
}

AMateria &AMateria::operator=( AMateria const &rhs ) {
	std::cout << "AMateria copy assignment called\n";
	if (this != &rhs)
		AMateria::operator=(rhs);
	return *this;
}

std::string const &AMateria::getType( void ) const {
	return this->type;
}

void AMateria::use( ICharacter& target ) {
	std::cout << "* uses " << this->type
		<< " materia on " << target.getName() << " *" << std::endl;
}
