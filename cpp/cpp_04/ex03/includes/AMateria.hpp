/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:51:19 by pamallet          #+#    #+#             */
/*   Updated: 2025/09/02 10:39:16 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream> 
# include "../includes/ICharacter.hpp"

class AMateria {

	protected:
		std::string type;

	public:
		AMateria( std::string const & type );
		AMateria( void );
		AMateria( AMateria const &src );
		virtual ~AMateria();

		AMateria &operator=( AMateria const &rhs );

		std::string const &getType( void ) const;

		virtual AMateria* clone( void ) const = 0;
		virtual void use( ICharacter& target );

};

#endif