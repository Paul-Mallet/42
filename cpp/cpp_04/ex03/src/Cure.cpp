/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:11:43 by pamallet          #+#    #+#             */
/*   Updated: 2025/09/02 10:32:15 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
    std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(std::string const &type) : AMateria(type) {
    std::cout << "Cure parameterized constructor called" << std::endl;
}

Cure::Cure(Cure const &src) : AMateria() {
    std::cout << "Cure copy constructor called" << std::endl;
    if (this != &src)
		this->type = src.type;
}

Cure::~Cure() {
    std::cout << "Cure destructor called" << std::endl;
}

// AMateria::operator=(rhs) because type is an inherent property of the class
Cure &Cure::operator=(Cure const &rhs) {
    std::cout << "Cure assignment operator called" << std::endl;
    if (this != &rhs)
        AMateria::operator=(rhs);
    return *this;
}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals "
        << target.getName() << "'s wounds *" << std::endl;
}
