/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:40:26 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/12/18 19:05:56 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

	public:
		WrongCat( void );
		WrongCat( std::string type );
		WrongCat( WrongCat const &src);
		~WrongCat();

		WrongCat	&operator=( WrongCat const &rhs );

		void		makeSound( void ) const;

};

#endif