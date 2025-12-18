/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:40:26 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/12/18 18:45:00 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {

	public:
		Cat( void );
		Cat( std::string type );
		Cat( Cat const &src);
		~Cat();

		Cat		&operator=( Cat const &rhs );

		void	makeSound( void ) const;

};

#endif