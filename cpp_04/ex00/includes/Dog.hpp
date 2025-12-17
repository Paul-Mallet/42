/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:38:05 by pamallet          #+#    #+#             */
/*   Updated: 2025/12/17 17:53:07 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {

	public:
		Dog( void );
		Dog( std::string name );
		Dog( Dog &src );
		~Dog();

		Dog &operator=( Dog &rhs );

		Dog makeSound( void );
};

#endif