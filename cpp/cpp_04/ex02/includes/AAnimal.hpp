/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:02:20 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/12/22 11:12:30 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

/**
 * @class AAnimal
 * @brief An AAnimal which cannot be directly instanciated due to:
 * * it's pure virtual methods declaration.
 * 
 * @date 12/22/2025
 * @author Paul Mallet
 * 
 * @param string type - AAnimal type.
 * @see Cat, Dog, Brain
 */
class AAnimal {

	protected:
		std::string type; //const?

	public:
		AAnimal( void );
		AAnimal( std::string type );
		AAnimal( AAnimal const &src );
		virtual ~AAnimal();

		AAnimal				&operator=( AAnimal const &rhs );
		virtual AAnimal*	clone( void ) = 0;

		std::string const			getType( void ) const;
		virtual std::string	const	getIdea( unsigned int i ) = 0;
		virtual void				setIdea( std::string idea, unsigned int i) = 0;
		virtual void				makeSound( void ) const = 0;
};

std::ostream &operator<<( std::ostream const &o, AAnimal const &i );

#endif