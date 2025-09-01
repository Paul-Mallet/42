/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:11:43 by pamallet          #+#    #+#             */
/*   Updated: 2025/09/01 18:35:18 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

Ice::Ice(void) : AMateria("ice") {
    std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(std::string const &type) : AMateria(type) {
    std::cout << "Ice parameterized constructor called" << std::endl;
}

Ice::Ice(Ice const &src) {
    std::cout << "Ice copy constructor called" << std::endl;
    if (this != &src)
		this->type = src.type;
}

Ice::~Ice() {
    std::cout << "Ice destructor called" << std::endl;
}

Ice &Ice::operator=(Ice const &rhs) {
    std::cout << "Ice assignment operator called" << std::endl;
    if (this != &rhs)
        AMateria::operator=(rhs);
    return *this;
}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at "
		<< target.getName() << " *" << std::endl;
}
