/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:29:02 by pamallet          #+#    #+#             */
/*   Updated: 2025/12/21 15:38:42 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

/**
 * @class Animal
 * @brief A mammifere which makeSound and have a brain.
 * * This is an abstract class (= 0 member function)
 * 
 * @date 21/12/2025
 * @author Paul Mallet
 * 
 * @param string - Le type de l'animal
 * @see Cat, Dog
 * @warning Properly delete previous Object(Cat or Dog) before using copy assignement.
 */
class Animal
{
	protected:
		std::string type;

	public:
		Animal( void );
		Animal( std::string type );
		Animal( Animal const &src );
		virtual ~Animal	();

		Animal				&operator=( Animal const &rhs );
		virtual Animal		*clone( void ) = 0;

		std::string					getType( void ) const;
		virtual std::string	const	getIdea( unsigned int i ) = 0;
		virtual void				setIdea( std::string idea, unsigned int i ) = 0;

		virtual void		makeSound( void ) const;
};

std::ostream &operator<<( std::ostream &o, Animal const &i);

#endif