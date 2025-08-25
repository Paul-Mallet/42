/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:55:16 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/25 09:13:28 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {

	public:
		Dog( void );
		Dog( std::string type );
		Dog( Dog const &src );
		~Dog();

		Dog &operator=( Dog const &rhs );

		void makeSound( void ) const;

};

#endif