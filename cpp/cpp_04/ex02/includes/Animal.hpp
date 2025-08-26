/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:43:46 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/26 09:01:56 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {

	public:
		Animal( void );
		Animal( std::string type );
		Animal( Animal const &src );
		virtual ~Animal();

		Animal &operator=( Animal const &rhs );

		std::string getType( void ) const;

		virtual void makeSound( void ) const = 0;

	protected:
		std::string type;
};

#endif