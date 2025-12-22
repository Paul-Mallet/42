/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:29:02 by pamallet          #+#    #+#             */
/*   Updated: 2025/12/18 19:05:52 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGWrongAnimal_HPP
# define WRONGWrongAnimal_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal( void );
		WrongAnimal( std::string type );
		WrongAnimal( WrongAnimal const &src );
		~WrongAnimal();

		WrongAnimal	&operator=( WrongAnimal const &rhs );

		std::string	getType( void ) const;

		void		makeSound( void ) const;
};

std::ostream &operator<<( std::ostream &o, WrongAnimal const &i);

#endif