/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:56:24 by pamallet          #+#    #+#             */
/*   Updated: 2025/09/02 16:06:25 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"
#include "../includes/ICharacter.hpp"

MateriaSource::MateriaSource( void ) {
	std::cout << "MateriaSource default constructor called\n";
    for (int i = 0; i < 4; i++) {
        _templates[i] = NULL;
    }
}

// AMateria::AMateria( std::string const &type ) : type(type) {
// 	std::cout << "AMateria parameterized constructor called\n";
// }

MateriaSource::MateriaSource( MateriaSource const &src ) {
    std::cout << "MateriaSource copy constructor called\n";
    for (int i = 0; i < 4; i++) {
        _templates[i] = NULL;
    }
    copyTemplates(src);
}

MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource destructor called\n";
    clearTemplates();
}

MateriaSource &MateriaSource::operator=( MateriaSource const &rhs ) {
    std::cout << "MateriaSource assignment operator called\n";
    if (this != &rhs)
	{
        clearTemplates();
        copyTemplates(rhs);
    }
    return *this;
}

void MateriaSource::learnMateria( AMateria *m ) {
	if (!m)
	{
		std::cout << "Cannot learn NULL materia\n";
        return ;
	}
	int slot = findEmptySlot();
    if (slot == -1)
	{
        std::cout << "MateriaSource memory is full, cannot learn " << m->getType() << std::endl;
        delete m;
        return ;
    }
    _templates[slot] = m->clone();
    std::cout << "MateriaSource learned " << m->getType() << " in slot " << slot << std::endl;
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const &type) {
    int slot = findMateriaByType(type);
    if (slot == -1)
	{
        std::cout << "MateriaSource doesn't know how to create " << type << std::endl;
        return NULL;
    }
    AMateria* newMateria = _templates[slot]->clone();
    std::cout << "MateriaSource created " << type << " materia\n";
    return newMateria;
}

void MateriaSource::clearTemplates( void ) {
    for (int i = 0; i < 4; i++)
	{
        if (_templates[i] != NULL)
		{
            delete _templates[i];
            _templates[i] = NULL;
        }
    }
}

void MateriaSource::copyTemplates( MateriaSource const &src ) {
    for (int i = 0; i < 4; i++)
	{
        if (src._templates[i] != NULL)
            _templates[i] = src._templates[i]->clone();
        else
            _templates[i] = NULL;
    }
}

int MateriaSource::findEmptySlot() const {
    for (int i = 0; i < 4; i++)
	{
        if (_templates[i] == NULL)
            return i;
    }
    return -1;
}

int MateriaSource::findMateriaByType( std::string const &type ) const {
    for (int i = 0; i < 4; i++)
	{
        if (_templates[i] != NULL
			&& _templates[i]->getType() == type)
            return i;
    }
    return -1;
}
