/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:10:41 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/12/22 11:12:20 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

/**
 * @class Dog
 * @brief A dog which makes bark sounds and have many ideas.
 * * This is a virtual class (virtual destructor by dft from AAnimal)
 * 
 * @date 12/22/2025
 * @author Paul Mallet
 * 
 * @param string type - AAnimal's type.
 * @param pointer _brain - Object pointer to Brain.
 * @see AAnimal, Cat, Brain
 */
class Dog : public AAnimal {

	private:
		Brain	*_brain;

	public:
		Dog( void );
		Dog( std::string type );
		Dog( Dog const &src);
		virtual ~Dog();

		Dog							&operator=( Dog const &rhs );
		virtual AAnimal				*clone( void );

		virtual std::string const	getIdea( unsigned int i );
		virtual void				setIdea( std::string idea, unsigned int i );

		void						makeSound( void ) const;

};

#endif