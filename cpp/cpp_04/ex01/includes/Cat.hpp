/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:55:16 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/26 08:40:50 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {

	public:
		Cat( void );
		Cat( std::string type );
		Cat( Cat const &src );
		~Cat();

		Cat &operator=( Cat const &rhs );

		void makeSound( void ) const;

	private:
		Brain *_brain;

};

#endif