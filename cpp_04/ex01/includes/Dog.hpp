/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:10:41 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/12/19 18:18:47 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {

	private:
		Brain *_brain;

	public:
		Dog( void );
		Dog( std::string type );
		Dog( Dog const &src);
		~Dog();

		Dog		&operator=( Dog const &rhs );

		void	makeSound( void ) const;

};

#endif