/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:29:02 by pamallet          #+#    #+#             */
/*   Updated: 2025/12/17 17:49:01 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
	protected:
		std::string type;

	public:
		Animal( void );
		Animal( std::string type );
		Animal( Animal const &src );
		virtual ~Animal	();

		Animal &operator=( Animal const &rhs );
		
		Animal getType( void );
		Animal makeSound( void );
};

#endif