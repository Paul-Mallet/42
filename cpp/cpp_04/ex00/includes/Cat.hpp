/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:55:16 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/25 09:14:20 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {

	public:
		Cat( void );
		Cat( std::string type );
		Cat( Cat const &src );
		~Cat();

		Cat &operator=( Cat const &rhs );

		void makeSound( void ) const;

};

#endif