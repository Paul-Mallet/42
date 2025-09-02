/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:44:32 by pamallet          #+#    #+#             */
/*   Updated: 2025/09/02 10:40:03 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

	public:
		MateriaSource( void );
		// MateriaSource(); param?
		MateriaSource( MateriaSource const &src );
		~MateriaSource();

		MateriaSource &operator=( MateriaSource const &rhs );

		void learnMateria( AMateria* );
		AMateria* createMateria( std::string const &type );

		void clearTemplates( void );
		void copyTemplates( MateriaSource const &src );

		int findEmptySlot() const;
		int findMateriaByType( std::string const &type ) const;

	private:
		AMateria* _templates[4];

};

#endif