/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:55:16 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/26 08:39:36 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {

	public:
		Dog( void );
		Dog( std::string type );
		Dog( Dog const &src );
		~Dog();

		Dog &operator=( Dog const &rhs );

		void makeSound( void ) const;

	private:
		Brain *_brain;

};

#endif