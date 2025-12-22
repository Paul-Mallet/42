/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:40:26 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/12/22 11:12:24 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

/**
 * @class Cat
 * @brief A cat which makes miaou sounds and have many ideas.
 * * This is a virtual class (virtual destructor by dft from AAnimal)
 * 
 * @date 12/22/2025
 * @author Paul Mallet
 * 
 * @param string type - Cat's type.
 * @param pointer _brain - Object pointer to Brain.
 * @see AAnimal, Dog, Brain
 */
class Cat : public AAnimal {

	private:
		Brain	*_brain;

	public:
		Cat( void );
		Cat( std::string type );
		Cat( Cat const &src);
		virtual ~Cat();

		Cat							&operator=( Cat const &rhs );
		virtual AAnimal				*clone( void );

		virtual std::string	const 	getIdea( unsigned int i );
		virtual void				setIdea( std::string idea, unsigned int i );

		void						makeSound( void ) const;

};

#endif