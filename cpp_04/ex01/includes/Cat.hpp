/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:40:26 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/12/21 15:39:14 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

/**
 * @class Cat
 * @brief A cat which makes miaou sounds and have many ideas.
 * * This is a virtual class (virtual destructor by dft from Animal)
 * 
 * @date 12/21/2025
 * @author Paul Mallet
 * 
 * @param string - Cat's type.
 * @see Animal, Dog
 */
class Cat : public Animal {

	private:
		Brain	*_brain;

	public:
		Cat( void );
		Cat( std::string type );
		Cat( Cat const &src);
		virtual ~Cat();

		Cat							&operator=( Cat const &rhs );
		virtual Animal				*clone( void );

		virtual std::string	const 	getIdea( unsigned int i );
		virtual void				setIdea( std::string idea, unsigned int i );

		void						makeSound( void ) const;

};

#endif